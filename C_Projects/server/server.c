#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

#define PORT        "3490"
#define BACKLOG     10

char *RESP = "HTTP/1.1 200 OK\nContent-Type: text/html; charset=UTF-8\nContent-Length: 53\nConnection: close\n\n<!DOCTYPE html><html><body><h1>Hello World!</h1></body></html>";

void sigchld_handler(int s) {
    int saved_errno = errno;
    int pid;
    while((pid = waitpid(-1, NULL, WNOHANG)) > 0) {
        fprintf(stdout, "servidor >> client's child process closed: %i\n", pid);
    }

    errno = saved_errno;
}

void *get_in_addr(struct sockaddr *sa) {
    if(sa->sa_family == AF_INET)
        return &(((struct sockaddr_in*) sa)->sin_addr);

    return &(((struct sockaddr_in6*) sa)->sin6_addr);
}

int send_handler(int sockfd, char *buf, int *len) {
    int total = 0;
    int bytesleft = *len;
    int n;

    while (total < *len) {
        n = send(sockfd, buf+total, bytesleft, 0);
        if(n == -1) {
            perror("servidor >> send");
            break;
        }
        total += n;
        bytesleft -= n;
    }

    *len = total;

    return n == -1? -1:0;
}

int main(void) {
    int sockfd, new_fd;
    struct addrinfo hints, *servinfo, *p;
    struct sockaddr_storage their_addr;
    socklen_t sin_size;
    struct sigaction sa;
    int yes = 1;
    char s[INET6_ADDRSTRLEN];
    int rv;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if((rv = getaddrinfo("0.0.0.0", PORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    for(p = servinfo; p != NULL; p = p->ai_next) {
        if((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("servidor >> socket");
            continue;
        }

        if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
            perror("servidor >> setsockopt");
            exit(1);
        }

        if(bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("servidor >> bind");
            continue;
        }

        break;
    }

    inet_ntop(p->ai_family, 
            get_in_addr((struct sockaddr*)p->ai_addr),
        s, sizeof s);

    printf("servidor >> IP address: %s\n", s);

    freeaddrinfo(servinfo);

    if (p == NULL) {
        fprintf(stderr, "servidor >> falha com bind.\n");
        exit(1);
    }

    if(listen(sockfd, BACKLOG) == -1) {
        perror("servidor >> listen");
        exit(1);
    }

    sa.sa_handler = sigchld_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;

    if(sigaction(SIGCHLD, &sa, NULL) == -1) {
        perror("servidor >> sigaction");
        exit(1);
    }

    printf("servidor >> aguardando por conexões...\n");

    while(1) {
        sin_size = sizeof their_addr;
        new_fd = accept(sockfd, (struct sockaddr*) &their_addr, &sin_size);
        if (new_fd == -1) {
            perror("servidor >> accept");
            continue;
        }

        inet_ntop(their_addr.ss_family, 
            get_in_addr((struct sockaddr*)&their_addr),
        s, sizeof s);
        printf("servidor >> conectado ao cliente: %s\n", s);

        if (!fork()) {
            close(sockfd);
            int len = strlen(RESP);
            if(send_handler(new_fd, RESP, &len) == -1)
                fprintf(stderr, "servidor >> send");
            
            /*char buf[1024] = {'\0'};
            if(recv(new_fd, buf, 1024, 0) == -1) {
                perror("servidor >> recv");
            }

            printf("servidor >> %s", buf);
            if(send(new_fd, "servidor >> ", 12, 0) == -1)
                perror("servidor >> send");
            if(send(new_fd, buf, 1024, 0) == -1)
                perror("servidor >> send");*/
            close(new_fd);
            exit(0);
        }
        close(new_fd); // processo pai não precisa disso.
    }

    return 0;
}
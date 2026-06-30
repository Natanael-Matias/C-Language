#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <sys/time.h>
#include <errno.h>

unsigned short calculate_checksum(const struct icmphdr * packet)
{
    const unsigned short * view = (const unsigned short *)packet;
    size_t size = sizeof(struct icmphdr);

    unsigned int sum = 0;
    for (; size > 1; size -= 2)
    {
        sum += *view++;
    }
    if (size == 1)
    {
        sum += *(unsigned char *)view;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    return ~sum;
}

void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int main(int argc, char const *argv[]) {
    int status, sock_fd;
    struct addrinfo hints, *servinfo, *p;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_RAW;
    hints.ai_protocol = IPPROTO_ICMP;
    hints.ai_flags = AI_PASSIVE;

    if ((status = getaddrinfo("155.10.10.102", NULL, &hints, &servinfo)) == -1) {
        fprintf(stderr, "gai error: %s\n", gai_strerror(status));
        exit(1);
    }

    for(p = servinfo; p != NULL; p = p->ai_next){
        if((sock_fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1){
            fprintf(stderr, "Erro no descritor de arquivos de socket.");
            perror("server: socket");
            continue;
        }

        int sec = 2;
        int usec = 500000;
        struct timeval tv_val;
        tv_val.tv_sec = sec;
        tv_val.tv_usec = usec;
        if (setsockopt(sock_fd, SOL_SOCKET, SO_RCVTIMEO, &tv_val, sizeof tv_val) == -1) {
            perror("setsockopt");
            exit(1);
        }

        break;
    }

    freeaddrinfo(servinfo);

    if (p == NULL){
        fprintf(stderr, "Err.");
        exit(1);
    }

    struct icmphdr hdr;
    hdr.type = ICMP_ECHO;
    hdr.un.echo.id = getpid();
    hdr.un.echo.sequence = 0;
    hdr.checksum = calculate_checksum(&hdr);

    sendto(sock_fd, &hdr, sizeof hdr, 0, get_in_addr((struct sockaddr *)p->ai_addr), sizeof(*(get_in_addr((struct sockaddr *)p->ai_addr))));

    char buffer[1024];
    int len = recvfrom(sock_fd, buffer, sizeof buffer, 0, NULL, NULL);

    buffer[len] = '\0';

    printf("%s\n", buffer);

    close(sock_fd);
    printf("Fim do programa.\n");
    return 0;
}


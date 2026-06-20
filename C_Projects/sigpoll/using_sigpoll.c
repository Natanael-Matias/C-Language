#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

void io_handler(int signo, siginfo_t *info, void *context) {
    if (signo == SIGPOLL) {
        /*const char msg[] = "I/O event caught via SIGPOLL!\n";
        write(STDOUT_FILENO, msg, sizeof(msg) - 1);*/
        char buf[1024] = {'\0'};
        read(STDOUT_FILENO, buf, sizeof buf);
        write(STDIN_FILENO, "echo >> ", 8);
        write(STDIN_FILENO, buf, sizeof buf);
    }
}

int main(void) {
    struct sigaction sa;

    sa.sa_sigaction = io_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO; // Required to use sa_sigaction instead of sa_handler

    if(sigaction(SIGPOLL, &sa, NULL) < 0) {
        perror("sigaction registration failed");
        exit(1);
    }

    // Direct standard input (STDIN_FILENO) to send an asynchronous I/O signal
    // Step A: Set this process as the owner of the file descriptor
    fcntl(STDIN_FILENO, F_SETOWN, getpid());

    // Step B: Enable asynchronous I/O notification flag
    int flags = fcntl(STDIN_FILENO, F_GETFL);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_ASYNC);

    printf("Type something and press Enter to trigger SIGPOLL...\n");

    // Infinite loop to keep program alive waiting for inputs
    while (1) {
        sleep(1);
        printf(">> aplication is runnig...\n");
    }

    return 0;
}
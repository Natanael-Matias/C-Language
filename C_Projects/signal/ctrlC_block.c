#include <stdio.h>
#include <signal.h>

void handler(int s) {
    printf("\nCtrl+C pressed!\nTry again...\n");
}

int main(void) {
    signal(SIGINT, handler);

    printf("Press enter to exit.\n");
    fflush(stdout);
    getchar();

    return 0;
}
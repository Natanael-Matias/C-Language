#include <stdio.h>
#include <stdlib.h>

#define a   "/sys/class/gpio/"
#define b   "value"

int main(void) {
    char buf[50];

    int len = snprintf(buf, sizeof buf, a "gpio%d/" b, 432);

    printf("%s\nlen = %d", buf, len);
}
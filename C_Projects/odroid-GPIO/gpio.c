#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#include "gpio.h"

#define gpioDir      "/sys/class/gpio/"
#define direction    "direction"
#define value        "value"
#define export       "export"
#define release      "unexport"
#define out          "out"
#define in           "in"

typedef void (*pCommand)(pin_t pin);

pCommand command[2] = {
    reset_pin,
    set_pin
};

static void export_pin(pin_t pin) {
    char buf[5];
    int fp, len;
    
    send_log(">> Caminho para config de export do pino %d: %s\n", pin, gpioDir export);

    if ((fp = open(gpioDir export, O_WRONLY)) == -1){
        perror(">> Export: Erro ao abrir diretorio.");
        exit(1);
    }

    len = snprintf(buf, sizeof buf, "%d", pin);
    if (write(fp, buf, len) != len){
        perror(">> Export: Erro na escrita.");
        exit(1);
    }

    close(fp);
}

static void direction_pin(pin_t pin, const int dir) { // dir = 0 -> out, 1 -> in
    char buf[50];
    int fp;
    
    snprintf(buf, sizeof buf, gpioDir "gpio%d/" direction, pin);
    send_log(">> Caminho para config de direcao do pino %d: %s\n", pin, buf);

    if((fp = open(buf, O_WRONLY)) == -1) {
        perror(">> Direction: Erro ao abrir diretorio.");
        exit(1);
    }

    char *msg = dir ? in : out;
    int len = strlen(msg);
    if(write(fp, msg, len) != len){
        perror(">> Direction: Erro na escrita.");
        exit(1);
    }

    close(fp);
}

static void release_pin(pin_t pin){
    char buf[5];
    int fp, len;
    
    send_log(">> Caminho para config de unexport do pino %d: %s\n", pin, gpioDir release);

    if ((fp = open(gpioDir release, O_WRONLY)) == -1){
        perror(">> Export: Erro ao abrir diretorio.");
        exit(1);
    }

    len = snprintf(buf, sizeof buf, "%d", pin);
    if (write(fp, buf, len) != len){
        perror(">> Export: Erro na escrita.");
        exit(1);
    }

    close(fp);
}

void set_pin(pin_t pin) {
    char buf[50];
    int fp;

    /* export pin */
    export_pin(pin);

    /* configure direction */
    direction_pin(pin, 0);
    
    snprintf(buf, sizeof buf, gpioDir "gpio%d/" value, pin);
    if ((fp = open(buf, O_WRONLY)) == -1) {
        perror(">> Set pin: Erro ao abrir diretorio.");
        exit(1);
    }

    int len = strlen(SET);
    if (write(fp, SET, len) != len) {
        perror(">> Set pin: Erro na escrita.");
        exit(1);
    }
    
    release_pin(pin);
    close(fp);
}

void reset_pin(pin_t pin) {
    char buf[50];
    int fp;

    /* export pin */
    export_pin(pin);

    /* configure direction */
    direction_pin(pin, 0);

    snprintf(buf, sizeof buf, gpioDir "gpio%d/" value, pin);
    if ((fp = open(buf, O_WRONLY)) == -1) {
        perror(">> Reset pin: Erro ao abrir diretorio.");
        exit(1);
    }

    int len = strlen(RESET);
    if (write(fp, RESET, len) != len) {
        perror(">> RESET: Erro na escrita.");
        exit(1);
    }

    release_pin(pin);
    close(fp);
}

int write_pin(pin_t pin, const int pin_value) {
    switch (pin_value) {
        case 0:
        case 1:
            command[pin_value](pin);
            break;
        default:
            fprintf(stderr, ">> Incorrect value: %d\n", pin_value);
            return -1;
    }
    
    return 0;
}


int read_pin(pin_t pin) {
    char buf[50];
    int fp;

    /* export pin */
    export_pin(pin);

    /* configure direction */
    direction_pin(pin, 0);

    snprintf(buf, sizeof buf, gpioDir "gpio%d/" value, pin);
    if ((fp = open(buf, O_RDONLY)) == -1) {
        perror(">> Read pin: Erro ao abrir diretorio.");
        return -1;
    }

    char msg[2];
    if (read(fp, msg, sizeof msg) == -1) {
        perror(">> Read pin: Erro na leitura.");
        return -1;
    }

    release_pin(pin);
    close(fp);

    return atoi(msg);
}

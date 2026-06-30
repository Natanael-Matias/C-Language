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

typedef status_t (*pCommand)(pin_t pin);

pCommand command[2] = {
    reset_pin,
    set_pin
};

static status_t export_pin(pin_t pin) {
    char buf[5];
    int fp, len;
    status_t status = ok;

    char gpio_path[50];
    snprintf(gpio_path, sizeof gpio_path, gpioDir "gpio%d", pin);
    if (!(access(gpio_path, F_OK))){
        send_log(">> [export_pin] Pino previamente exportado.");
        return status;
    }
    
    send_log(">> [export_pin] Caminho para config de export do pino %d: %s\n", pin, gpioDir export);

    if ((fp = open(gpioDir export, O_WRONLY)) == -1){
        perror(">> [export_pin] Erro ao abrir diretorio.");
        return err;
    }
    
    len = snprintf(buf, sizeof buf, "%d", pin);
    if (write(fp, buf, len) != len){
        perror(">> [export_pin] Erro na escrita.");
        status = err;
    }

    usleep(1000);
    close(fp);

    return status;
}

static status_t direction_pin(pin_t pin, const int dir) { // dir = 0 -> out, 1 -> in
    char buf[50];
    int fp;
    status_t status =  ok;
    
    snprintf(buf, sizeof buf, gpioDir "gpio%d/" direction, pin);
    send_log(">> [direction_pin] Caminho para config de direcao do pino %d: %s\n", pin, buf);

    if((fp = open(buf, O_WRONLY)) == -1) {
        perror(">> [direction_pin] Erro ao abrir diretorio.");
        return err;
    }

    char *msg = dir ? in : out;
    int len = strlen(msg);
    if(write(fp, msg, len) != len){
        perror(">> [direction_pin] Erro na escrita.");
        status = err;
    }

    usleep(1000);
    close(fp);

    return status;
}

static status_t release_pin(pin_t pin){
    char buf[5];
    int fp, len;
    status_t status = ok;
    
    send_log(">> [release_pin] Caminho para config de unexport do pino %d: %s\n", pin, gpioDir release);

    if ((fp = open(gpioDir release, O_WRONLY)) == -1){
        perror(">> [release_pin] Erro ao abrir diretorio.");
        return err;
    }

    len = snprintf(buf, sizeof buf, "%d", pin);
    if (write(fp, buf, len) != len){
        perror(">> [release_pin] Erro na escrita.");
        status = err;
    }

    close(fp);
    return status;
}

status_t set_pin(pin_t pin) {
    char buf[50];
    int fp;
    status_t status = ok;

    /* export pin */
    if (!export_pin(pin))
        return err;

    /* configure direction */
    if (!direction_pin(pin, 0)){
        release_pin(pin);
        return err;
    }
        
    
    snprintf(buf, sizeof buf, gpioDir "gpio%d/" value, pin);
    if ((fp = open(buf, O_WRONLY)) == -1) {
        perror(">> [set_pin] Erro ao abrir diretorio.");
        release_pin(pin);
        return err;
    }

    int len = strlen(SET);
    if (write(fp, SET, len) != len) {
        perror(">> [set_pin] Erro na escrita.");
        status = err;
    }
    
    close(fp);
    release_pin(pin);

    return status;
}

status_t reset_pin(pin_t pin) {
    char buf[50];
    int fp;
    status_t status = ok;

    /* export pin */
    if (!export_pin(pin))
        return err;

    /* configure direction */
    if (!direction_pin(pin, 0)){
        release_pin(pin);
        return err;
    }
        

    snprintf(buf, sizeof buf, gpioDir "gpio%d/" value, pin);
    if ((fp = open(buf, O_WRONLY)) == -1) {
        perror(">> [reset_pin] Erro ao abrir diretorio.");
        release_pin(pin);
        return err;
    }

    int len = strlen(RESET);
    if (write(fp, RESET, len) != len) {
        perror(">> [reset_pin] Erro na escrita.");
        status = err;
    }
    
    close(fp);
    release_pin(pin);

    return status;
}

void write_pin(pin_t pin, const int pin_value) {
    switch (pin_value) {
        case 0:
        case 1:
            command[pin_value](pin);
            break;
        default:
            fprintf(stderr, ">> [write_pin] Incorrect value: %d\n", pin_value);
            exit(1);
    }
}


int read_pin(pin_t pin) {
    char buf[50];
    int fp;

    /* export pin */
    if (!export_pin(pin))
        return -1;

    /* configure direction */
    if (!direction_pin(pin, 1)) {
        release_pin(pin);
        return -1;
    };

    snprintf(buf, sizeof buf, gpioDir "gpio%d/" value, pin);
    if ((fp = open(buf, O_RDONLY)) == -1) {
        perror(">> [read_pin] Erro ao abrir diretorio.");
        release_pin(pin);
        return -1;
    }

    char msg[2] = {0};
    if (read(fp, msg, 1) == -1) {
        perror(">> [read_pin] Erro na leitura.");
        close(fp);
        release_pin(pin);
        return -1;
    }

    close(fp);
    release_pin(pin);

    return atoi(msg);
}

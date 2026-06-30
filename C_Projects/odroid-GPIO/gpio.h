#ifndef _GPIO_H
#define _GPIO_H

#include <stdio.h>

#ifdef ODROID_C4
    typedef enum{
        gpioh_5     = 432,
        gpioh_6     = 433,
        gpioh_7     = 434,
        gpioa_14    = 474,
        gpioa_15    = 475,
        gpiox_0     = 476,
        gpiox_1     = 477,
        gpiox_2     = 478,
        gpiox_3     = 479,
        gpiox_4     = 480,
        gpiox_5     = 481,
        gpiox_6     = 482,
        gpiox_7     = 483,
        gpiox_8     = 484,
        gpiox_9     = 485,
        gpiox_10    = 486,
        gpiox_11    = 487,
        gpiox_12    = 488,
        gpiox_13    = 489,
        gpiox_14    = 490,
        gpiox_15    = 491,
        gpiox_16    = 492,
        gpiox_17    = 493,
        gpiox_18    = 494,
        gpiox_19    = 495
    }pin_t;
#else
    typedef int pin_t;
#endif

#define SET     "1"
#define RESET   "0"

#ifdef DEBUG
    #define send_log(msg, ...)      printf(msg, ##__VA_ARGS__)
#else
    #define send_log(msg, ...)      (void)0
#endif

typedef enum {
    err,
    ok
} status_t;

void write_pin(pin_t pin, int pin_value);
int read_pin(pin_t pin);

/*
TODO: Implementar rotinas para definição do pull-up/pull-down
TODO: Implementar rotinas para interrupção de GPIO.
TODO: Implementar mapeamento dos pinos
TODO: Implementar info dos pinos
*/

#endif
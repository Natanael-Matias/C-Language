#include "gpio.h"
#include <unistd.h>

int main()
{    
    /* blink  - hello world */

    while(1){
        set_pin(gpioh_5);
        sleep(1);
        reset_pin(gpioh_5);
        sleep(1);
    }

    return 0;
}
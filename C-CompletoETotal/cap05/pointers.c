#include <stdio.h>
#include <stdlib.h>

void PointerTypes(void);

void main(void) {
    PointerTypes();   
}

/*
* Exemplo da página 115 que ilustra o fato de que um ponteiro
* sempre deve apontar para o tipo correto.
*/

void PointerTypes(void) {
    float x, y;
    int *p;

    /* O próximo comando faz com que p (que é ponteiro
    para inteiro) aponte para um float. */
    x = 10.5;
    p = &x; // [-Wincompatible-pointer-types]

    /* O próximo comando não funciona como esperado. */
    y = *p;

    printf("%d\n", y);
}
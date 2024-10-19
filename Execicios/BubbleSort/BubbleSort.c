/*
Implemente o algoritmo Bubble Sort para ordenar um array de números inteiros em ordem crescente.

Entrada: Um array de números inteiros e seu tamanho.
Saída: O array ordenado.
*/
#include <stdio.h>

void BubbleSort(int *array, int len);

void main(void) {
    int numbers[] = {10, 5, 7, 2, 1, 0, 3, 7, 8, 4};
    int n = sizeof(numbers)/sizeof(int);

    for (int i = 0; i < n; i++) {
        printf("%5d", numbers[i]);
    }
    printf("\n");

    BubbleSort(numbers, n);

    for (int i = 0; i < n; i++) {
        printf("%5d", numbers[i]);
    }
    printf("\n");
}

void BubbleSort(int *array, int len) {
    int i, j, temp;

    for (i = 0; i < len - 1; i++){
        temp = 0;
        for (j = 0; j < len - i - 1; j++) {
            if (array[j] > array[j + 1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
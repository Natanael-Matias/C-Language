#include <stdio.h>
#include <stdint.h>

#define ALIVE       0xB2
#define DEAD        0xB0
#define LENGTH      61
#define GENERATION  31

typedef enum {
    dead = 0,
    alive
} BOOL;

BOOL prevGen[LENGTH] = {dead};
BOOL nextGen[LENGTH];

char ConvState (BOOL state);
BOOL CellState (BOOL left, BOOL right);
void printCell(BOOL cellState);

void main(void) {
    prevGen[LENGTH/2] = alive;

    for (int i = 0; i < GENERATION; i++) {
        for (int i = 0; i < LENGTH; i++) {
            printCell(prevGen[i]);
            if (i == 0)                 nextGen[i] = CellState(prevGen[LENGTH-1], prevGen[i+1]);
            else if (i == LENGTH-1)     nextGen[i] = CellState(prevGen[i-1], prevGen[0]);
            else                        nextGen[i] = CellState(prevGen[i-1], prevGen[i+1]);
        }
        
        for(int i = 0; i < LENGTH; i++)
            prevGen[i] = nextGen[i];

        printf("\n");
    }

}

char ConvState (BOOL state) {
    return state ? ALIVE : DEAD; 
}

BOOL CellState (BOOL stateLeft, BOOL stateRight) {    
    return (stateLeft ^ stateRight);
}

void printCell(BOOL cellState) {
    printf("%c", ConvState(cellState));
}
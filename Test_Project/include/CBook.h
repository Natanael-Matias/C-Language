#ifndef INC_CBOOK_H_
#define INC_CBOOK_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void TiposPrimitivosC(void);
void gotoxy(int x, int y);
void converge(int line, char *message);

/* Jogo da velha*/
extern char matrix[3][3];
char check(void);
void InitMatrix(void);
void GetPlayerMove(void);
void GetComputerMove(void);
void DispMatrix(void);

#endif
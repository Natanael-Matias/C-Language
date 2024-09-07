#include <stdio.h>
#include <string.h>
#include "Utils.h"
#include "CBook.h"
#include "binomio.h"

char matrix[3][3];

void main(void)
{
	char done;

	printf("Este é o jogo da velha.\n");
	printf("Você estará jogando contra o computador.\n");

	done = ' ';
	InitMatrix();
	do{
		DispMatrix();
		GetPlayerMove();
		done = check();
		if (done != ' ') break;
		GetComputerMove();
		done = check();
	} while (done == ' ');

	DispMatrix();
	if (done == 'X') printf("Você venceu!\n");
	else printf("Eu venci!!!!\n");
}
#include "CBook.h"

void TiposPrimitivosC(void){
	printf("int:		%li bits\n", sizeof(int)*8);
	printf("short int:	%li bits\n", sizeof(short int)*8);
	printf("long int:	%li bits\n", sizeof(long int)*8);
	printf("char:		%li bits\n", sizeof(char)*8);
	printf("float:		%li bits\n", sizeof(float)*8);
	printf("double:		%li bits\n", sizeof(double)*8);
	printf("long double:	%li bits\n", sizeof(long double)*8);
}

void gotoxy(int x, int y){
	printf("\033[%d;%dH", y, x);
}

void converge(int line, char *message){
	int i, j;

	for (i = 1, j = strlen(message); i <= j; i++, j--)
	{
		gotoxy(i, line); 
		printf("%c", message[i-1]);
		gotoxy(j, line); 
		printf("%c", message[j-1]);
	}
}

/*Jogo da velha*/
void InitMatrix(void){
	int i,j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			matrix[i][j] = ' ';
}

void GetPlayerMove(void){
	int x, y;

	printf("Digite as coordenadas para o X: ");
	scanf("%d%d", &x, &y);

	x--; y--;

	if (matrix[x][y] != ' '){
		printf("Posição inválida, tente novamente. \n");
		GetPlayerMove();
	}
	else matrix[x][y] = 'X';
}

void GetComputerMove(void){
	int i, j;

	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++)
			if(matrix[i][j] == ' ') break;
		if(matrix[i][j] == ' ') break;
	}
	
	if (i*j == 9){
		printf("empate.\n");
		exit(0);
	}
	else
		matrix[i][j] = 'O';
}

void DispMatrix(void){
	int t;

	for(t = 0; t < 3; t++){
		printf(" %c | %c | %c ", matrix[t][0], matrix[t][1], matrix[t][2]);
		if(t != 2) printf("\n---|---|---\n");
	}
	printf("\n");
}

char check(void){
	int i;

	for (i = 0; i < 3; i++)
		if (matrix[i][0] == matrix[i][1] &&
		    matrix[i][0] == matrix[i][2]) return matrix[i][0];
	
	for (i = 0; i < 3; i++)
		if (matrix[0][i] == matrix[1][i] &&
		    matrix[0][i] == matrix[2][i]) return matrix[0][i];

	if (matrix[0][0] == matrix[1][1] &&
	    matrix[1][1] == matrix[2][2])
		return matrix[0][0];
	
	if (matrix[0][2] == matrix[1][1] &&
	    matrix[1][1] == matrix[2][0])
		return matrix[0][2];
	
	return ' ';		
}
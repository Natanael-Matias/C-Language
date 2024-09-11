#include <stdio.h>
#include <string.h>
#include "Utils.h"
#include "CBook.h"
#include "binomio.h"

Bool testeBool(int a, int b){
	if (a > b) return TRUE;
	return FALSE;
}

void main(void)
{
	int a = 15, b = 13;
	if (testeBool(a,b))
		printf("MAIOR!\n");
	else
		printf("MENOR!\n");
}
#ifndef INC_BINOMIO_H_
#define INC_BINOMIO_H_

/*Função que calcula o fatorial*/
uint32_t Fatorial(int numero){
	if(numero == 0) return 1;

	uint32_t fat = 1;
	for(int i = 1; i <= numero; i++){
		fat = fat * i;
	}
	return fat;
}


/*Realiza a divisão entre dois fatoriais*/
uint32_t SimplificaFatorial(int i, int j){ // i: linha 		j: coluna
	int diff = i - j;
	uint32_t temp;
	uint32_t fat = 1;

	if(diff > 0){
		temp = i;

		while(temp > j){
			fat = fat * temp;
			temp--;
		}
	}
	else{
		temp = j;

		while(temp > i){
			fat = fat * temp;
			temp--;
		}
	}
	return fat;
}

int CalculaBinomio(int n, int k){
	uint32_t temp = SimplificaFatorial(n,k);
	int difffat = Fatorial(n-k);
	int resul = temp/difffat;

	return resul;
}

void tringuloPascal(int linhas){
	for (int i = 0; i < linhas; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			printf("%d\t\t", CalculaBinomio(i,j));
		}
		printf("\n");
	}
}

#endif
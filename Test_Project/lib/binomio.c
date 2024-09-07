#include "binomio.h"

// Função que calcula o fatorial
double Fatorial(int numero){
    double fatorial = 1;

    if(numero){
        for (int i = numero; i > 1; i--)
        {
            fatorial *= i;
        }
    }
    return fatorial;
}

// Realiza a divisão entre dois fatoriais
double SimplificaFatorial(int i, int j){
    int diff = i - j;
    double temp;
    double resultadoDivisão = 1;

    if(diff > 0){
        temp = i;
        while(temp > j){
            resultadoDivisão *= temp;
            temp--;
        }
    }
    else{
        temp = j;
        while(temp > i){
            resultadoDivisão *= temp;
            temp--;
        }
    }
    return resultadoDivisão;
}

double CalculaBinomio(int n, int k){
    double temp = SimplificaFatorial(n,k);
    double diffFatorial = Fatorial(n-k);
    return temp/diffFatorial;
}

// Constroi o triangulo de PASCAL até nLinhas linha.
void TrianguloPascal(int nLinhas){
    double tempD;
    float tempF;
    int tempI;
    for (int i = 0; i < nLinhas; i++)
    {
        int cont = 0;
        for (int j = i; j > i/2; j--)
        {
            tempD = CalculaBinomio(i,j);
            tempF = tempD;
            tempI = tempF;
            printf("%d\t", tempI);
            cont++;
        }
        for (int j = cont; j <= i; j++)
        {
            tempD = CalculaBinomio(i,j);
            tempF = tempD;
            tempI = tempF;
            printf("%d\t", tempI);
        }
        printf("\n");
    }
}
#include <stdio.h>

void DotProduct(int *vecA, int *vecB)
{
    int dotProduct = 0;
    int i = 0;

    while (i < 3)
    {
        dotProduct += vecA[i]*vecB[i];
        i++;
    }

    printf("Result: %d", dotProduct);
    
}

int main(int argc, char const *argv[])
{
    int vecA[3] = {1,2,3};
    int vecB[3] = {4,5,6};

    DotProduct(vecA,vecB);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Função dobra com parametro de valor
void dobraV(int numV){
    numV = numV * 2;
    printf("\nO valor de numV: %d\n", numV);
}

void dobraR(int *numR){
    *numR *= 2;
    printf("\nO valor de numR: %d\n", *numR);
}

int main(){
    // Passagem de parâmetro por valor e por referência!!!
    int num1 = 10;
    printf("O valor de num1: %d\n", num1);

    // Dobrando o num1 com a função com parâmetro por valor
    dobraV(num1);

    // Imprimindo o valor de num1 após dobraV
    printf("O valor de num1: %d\n", num1);

    // Dobrando o num1 com a função com parâmetro por referência
    dobraR(&num1);
    
    // Imprimindo o valor de num1 após dobraR
    printf("O valor de num1: %d\n", num1);

    return 0;
}

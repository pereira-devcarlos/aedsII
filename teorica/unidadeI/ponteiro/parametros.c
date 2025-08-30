#include <stdio.h>
#include <stdlib.h>

// Função dobra com parametro de valor
void dobra(int n){
    n = n * 2;
    printf("\nO valor de n: %d\n", n);
}

int main(){
    // Passagem de parâmetro por valor e por referência!!!
    int num1 = 10;
    dobra(num1);
    printf("O valor de num1: %d", num1);
    
    return 0;
}

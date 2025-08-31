#include <stdio.h>
#include <stdlib.h>

int main(){
    // Alocação Dinâmica de Memória, Aritméticas de Ponteiros
    int numElementos = 4;
    int* pont = malloc(sizeof(int));

    *pont = 10;
    printf("%d\n", *pont);

    free(pont);
    return 0;
}

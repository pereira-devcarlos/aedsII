#include <stdio.h>
#include <stdlib.h>

int main(){
    // Alocação Dinâmica de Memória
    int numElementos = 4;
    int* pont = malloc(numElementos * sizeof(int));

    // Aritméticas de Ponteiros
    for (int i = 0; i < numElementos; i++){
        *(pont + i) = i * 2;
        printf("%d\n", *(pont + i));
    }

    // Liberação da Memória (Obrigatório em Alocação Dinâmica)
    free(pont);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

void insere(int * p, int tamanho){
    for (int i = 0; i < tamanho; i++){
        p[i] = i * 2;
    }
    
}

void imprime(int * p, int tamanho){
    for (int i = 0; i < tamanho; i++){
        printf("%d\n", p[i]);
    }
    
}

int main(){
    // Alocação Dinâmica de Memória
    int numElementos = 4;
    int* pont = malloc(numElementos * sizeof(int));

    printf("Imprimindo usando funcoes com parametro por referencia: \n");
    insere(pont, numElementos);
    imprime(pont, numElementos);

    // Aritméticas de Ponteiros
    // 1° Notação é utilizando de maneira manualmente o ponteiro
    printf("\nNotacao de ponteiro:\n");
    for (int i = 0; i < numElementos; i++){
        *(pont + i) = i * 2;
        printf("%d\n", *(pont + i));
    }

    // 2° Notação é utilizar como se fosse um vetor mesmo
    printf("\nNotacao de vetor:\n");
    for (int i = 0; i < numElementos; i++){
        pont[i] = i + 3;
        printf("%d\n", pont[i]);
    }
    

    // Liberação da Memória (Obrigatório em Alocação Dinâmica)
    free(pont);
    return 0;
}

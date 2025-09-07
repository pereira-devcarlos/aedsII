#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    int valor;
    struct no* prox;
} No;

void insertFila(No * insere, No **inicio, No **fim){
    if (*fim != NULL){
        (*fim)->prox= insere;
    } else {
        *inicio = insere;
    }
    *fim = insere;
}

No* removeFila(No **inicio, No **fim){
    No * retorno = NULL;
    if (*inicio != NULL){
        retorno = *inicio;
        *inicio = (*inicio)->prox;

        // Caso a fila ficar vazia
        if (*inicio == NULL){
            *fim = NULL;
        }
    }
    return retorno;
}

int main(){
    No * inicio = NULL;
    No * fim = NULL;

    No* insere = (No*) malloc(sizeof(No));
    insere->chave= 1;
    insere->valor= 3;
    insere->prox= NULL;
    insertFila(insere, &inicio, &fim);
    printf("\nNo inserido: chave=%d, valor=%d", insere->chave, insere->valor);
    
    No* liberar = removeFila(&inicio, &fim);
    printf("\nRemovido: chave=%d, valor=%d\n", liberar->chave, liberar->valor);
    free(liberar);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    int valor;
    struct no* prox;
} No;

void insertFila(No * insere, No **fim, No **inicio){
    if (*fim != NULL){
        (*fim)->prox= insere;
    } else {
        *inicio = insere;
    }
    *fim = insere;
}

int main(){
    No * inicio = NULL;
    No * fim = NULL;

    No* insere = (No*) malloc(sizeof(No));
    insere->chave= 1;
    insere->valor= 3;
    insere->prox= NULL;
    insertFila(insere, &fim, &inicio);
    
    return 0;
}

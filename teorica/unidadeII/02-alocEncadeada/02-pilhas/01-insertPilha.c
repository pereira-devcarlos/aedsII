#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    int valor;
    struct no* prox;
} No;

void insertPilha(No* inserir, No* topo){
    inserir->prox = topo;
    topo = inserir;
}

int main(){
    No* topo = NULL;

    No * inserir = (No*) malloc(sizeof(No));
    inserir->chave=2;
    inserir->valor=5;
    inserir->prox=NULL;

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esq, *dir;
} No;

// Função de inserção sem retorno
void insere (No **raiz, int valor) {
    if (*raiz == NULL){
        *raiz = (No*) malloc(sizeof(No));
        (*raiz)->valor = valor;
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
    } else {
        if (valor < (*raiz)->valor){
            insere( &((*raiz)->esq), valor);
        } else {
            insere( &((*raiz)->dir), valor);
        }
    }
}

void preOrdem (No *raiz) {
    if (raiz == NULL){
        return;
    }
    printf("%d\n", raiz->valor);
    preOrdem(raiz->esq);
    preOrdem(raiz->dir);
}

void emOrdem (No *raiz) {
    if (raiz == NULL){
        return;
    }
    emOrdem(raiz->esq);
    printf("%d\n", raiz->valor);
    emOrdem(raiz->dir);
}

void posOrdem (No *raiz) {
    if (raiz == NULL){
        return;
    }
    posOrdem(raiz->esq);
    posOrdem(raiz->dir);
    printf("%d\n", raiz->valor);
}

int main(){
    No *raiz = NULL;

    // Testando as funções de inserir
    insere(&raiz, 5);
    insere(&raiz, 2);
    insere(&raiz, 8);

    printf("\nPre Ordem:\n");
    preOrdem(raiz);

    printf("\nEm Ordem:\n");
    emOrdem(raiz);

    printf("\nPos Ordem:\n");
    posOrdem(raiz);

    return 0;
}

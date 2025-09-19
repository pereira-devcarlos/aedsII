#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esq, *dir;
} No;

No* insere (No *raiz, int valor) {
    // Verificar se a raiz é NULL
    if (raiz == NULL){
        No *novo = (No*) malloc(sizeof(No));
        novo->valor = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    } else {
        if (valor < raiz->valor){
            raiz->esq = insere(raiz->esq, valor);
        } else {
            raiz->dir = insere(raiz->dir, valor);
        }
        return raiz;                   
    }
}

int main(){
    No *raiz = NULL;

    // Testando as funções de inserir
    raiz = insere(raiz, 5);
    raiz = insere(raiz, 2);
    raiz = insere(raiz, 8);


    return 0;
}

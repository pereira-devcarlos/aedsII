#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

// Fução para alocar um novo nó na memória
No *alocarNo(int valor){
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->dir = NULL;
    novo->esq = NULL;
}

// Função para inserir um nó na Arvore
No *insertNo(No *raiz, No *noInserir){
    if (noInserir == NULL) return NULL;
    
    if (noInserir->valor < raiz->valor){
        raiz->esq = insertNo(raiz->esq, noInserir);
    } else if (noInserir->valor > raiz->valor){
        raiz->dir = insertNo(raiz->dir, noInserir);
    } else {
        raiz = noInserir;
    }
}

int main(){
    
    return 0;
}

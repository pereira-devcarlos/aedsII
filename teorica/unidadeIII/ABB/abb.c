#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

// Fução para alocar um novo nó na memória
No *alocarNo(int valor){
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->dir = NULL;
    novo->esq = NULL;
    return novo;
}

// Função para inserir um nó na Arvore
No *insertNo(No *raiz, No *noInserir){
    if (raiz == NULL){
        return noInserir;
    }

    if (noInserir->valor < raiz->valor){
        raiz->esq = insertNo(raiz->esq, noInserir);
    } else if (noInserir->valor > raiz->valor){
        raiz->dir = insertNo(raiz->dir, noInserir);
    } else {
        raiz = noInserir;
    }
    return raiz;
}

// Função para buscar um no na Árvore
No *buscaNo(No *raiz, int valor){
    if (raiz == NULL){
        return NULL;
    }

    if (valor < raiz->valor){
        raiz = buscaNo(raiz->esq, valor);
    } else if (valor > raiz->valor){
        raiz = buscaNo(raiz->dir, valor);
    } 
    return raiz;
}

// Função para imprimir a arvore
void preOrdem(No *raiz){
    if (raiz != NULL){
        printf("%d ", raiz->valor);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void emOrdem(No *raiz){
    if (raiz != NULL){    
        emOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        emOrdem(raiz->dir);
    }
}

int main(){
    No *raiz = NULL;

    No *noInserir = alocarNo(10);
    raiz = insertNo(raiz, noInserir);

    noInserir = alocarNo(5);
    raiz = insertNo(raiz, noInserir);

    printf("\nArvore em pre ordem:\n");
    preOrdem(raiz);

    printf("\nArvore em ordem:\n");
    emOrdem(raiz);

    No *resultBusca = buscaNo(raiz, 7);
    if (resultBusca != NULL){
        printf("\nValor 7 foi encontrado!");
    } else {
        printf("\nValor 7 nao foi encontrado");
    }
    
    resultBusca = buscaNo(raiz, 5);
    if (resultBusca != NULL){
        printf("\nValor 5 foi encontrado!");
    } else {
        printf("\nValor 5 nao foi encontrado");
    }

    return 0;
}

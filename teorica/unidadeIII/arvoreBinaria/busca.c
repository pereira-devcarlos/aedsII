#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esq, *dir;
} No;

// Função de inserção com Retorno
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

// Função de Busca 
No* busca (No* raiz, int x){
    if (raiz == NULL || raiz->valor == x){
        return raiz;
    } else {
        if (x < raiz->valor){
            raiz = busca(raiz->esq, x);
        } else {
            raiz = busca(raiz->dir, x);
        }        
        return raiz;
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

    // Testando a função de inserir
    raiz = insere(raiz, 5);
    raiz = insere(raiz, 2);
    raiz = insere(raiz, 8);

    // Testando a função de busca
    No *teste = busca(raiz, 2);
    if (teste){
        printf("\nNo com o valor 2 encontrado!");
    } else {
        printf("\nNo com o valor 2 nao foi encontrado!");
    }
    
    teste = busca(raiz, 3);
    if (teste != NULL){
        printf("\nNo com o valor 3 encontrado!");
    } else {
        printf("\nNo com o valor 3 nao foi encontrado!");
    }

    return 0;
}

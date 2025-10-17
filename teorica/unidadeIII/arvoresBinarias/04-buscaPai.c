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

// Função de Buscar um nó
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

// Função de Buscar o pai
No* buscaPai (No* raiz, int x) {
    // Verificando se existe o nó a ser buscado o pai
    if (!busca(raiz, x)) return NULL;
    
    if (raiz == NULL || raiz->esq->valor == x || raiz->dir->valor == x){
        return raiz;
    } else {
        if (x < raiz->valor){
            raiz = buscaPai(raiz->esq, x);
        } else {
            raiz = buscaPai(raiz->dir, x);
        }        
        return raiz;
    }
} 

// Funções de impressões: pré ordem, em ordem e pós ordem 
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
    raiz = insere(raiz, 3);
    raiz = insere(raiz, 2);
    raiz = insere(raiz, 8);
    raiz = insere(raiz, 4);
    raiz = insere(raiz, 6);

    // Testando a função de busca
    No *teste = buscaPai(raiz, 6);
    if (teste){
        printf("\nPai de 6: %d", teste->valor);
    } else {
        printf("\nPai do 6 nao foi encontrado!");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esq, *dir;
} No;

No *alocarNo(int valor){
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
}

No *inserirNo(No *raiz, No *novo){
    // Arvore Vazia, nó inserido se torna a raiz
    if (raiz == NULL) return novo;
    
    No *aux = raiz;
    No *pai = NULL;
    while (aux != NULL){
        pai = aux;
        if (novo->valor < aux->valor){
            aux = aux->esq;
        } else if (novo->valor > aux->valor){
            aux = aux->dir;
        } else {
            return raiz;
        }
    }

    if (novo->valor < pai->valor){
        pai->esq = novo;
    } else {
        pai->dir = novo;
    }
    return raiz;
}

No *buscaNo(No *raiz, int valor){
    No *aux = raiz;
    while (aux != NULL){
        if (valor == aux->valor){
            return aux;
        } else if (valor < aux->valor){
            aux = aux->esq;
        } else {
            aux = aux->dir;
        } 
    }
    return NULL;
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
    raiz = inserirNo(raiz, noInserir);

    noInserir = alocarNo(5);
    raiz = inserirNo(raiz, noInserir);

    noInserir = alocarNo(2);
    raiz = inserirNo(raiz, noInserir);

    noInserir = alocarNo(7);
    raiz = inserirNo(raiz, noInserir);

    printf("\nArvore em pre ordem:\n");
    preOrdem(raiz);

    printf("\nArvore em ordem:\n");
    emOrdem(raiz);

    No *resultBusca = buscaNo(raiz, 9);
    if (resultBusca != NULL){
        printf("\nValor 9 foi encontrado!\n");
    } else {
        printf("\nValor 9 nao foi encontrado\n");
    }
    
    resultBusca = buscaNo(raiz, 5);
    if (resultBusca != NULL){
        printf("\nValor 5 foi encontrado!\n");
    } else {
        printf("\nValor 5 nao foi encontrado\n");
    }

    return 0;
}

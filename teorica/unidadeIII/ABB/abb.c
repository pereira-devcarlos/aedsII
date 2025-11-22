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

// Função para buscar o pai de um No
No *buscaPai(No *raiz, int valor){
    if (raiz == NULL || raiz->valor == valor){
        return NULL;
    }

    if (raiz->esq != NULL &&  raiz->esq->valor == valor){
        return raiz;
    } else if (raiz->dir != NULL && raiz->dir->valor == valor){
        return raiz;
    } else {
        if (valor < raiz->valor){
            raiz = buscaPai(raiz->esq, valor);
        } else {
            raiz = buscaPai(raiz->dir, valor);
        }
        return raiz;
    }
}

// Função para remover a raiz da árvore
No *removeRaiz(No *raiz){
    if (raiz == NULL) return NULL;
    
    No *p = raiz;
    No *q = (raiz->esq != NULL) ? raiz->esq : raiz;

    // Não possui filhos a esquerda
    if (p == q){
        q = p->dir;
        free(p);
        return q;
    }

    while (q->dir != NULL){
        p = q;
        q = q->dir;
    }
    
    if (p != raiz){
        p->dir = q->esq;
        q->esq = raiz->esq;
    }
    q->dir = raiz->dir;

    return q;    
}

// Função para remover um determinado nó da árvore
No *removerNo(No *raiz, int valor){
    No *n = buscaNo(raiz, valor);
    if (n){
        No *pai = buscaPai(raiz, valor);
        if (pai){
            if (pai->esq->valor == valor){
                pai->esq = removeRaiz(n);
            } else {
                pai->dir = removeRaiz(n);
            }
        } else {
            raiz = removeRaiz(n);
        }
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

    noInserir = alocarNo(2);
    raiz = insertNo(raiz, noInserir);

    noInserir = alocarNo(7);
    raiz = insertNo(raiz, noInserir);

    printf("\nArvore em pre ordem:\n");
    preOrdem(raiz);

    printf("\nArvore em ordem:\n");
    emOrdem(raiz);

    No *resultBusca = buscaNo(raiz, 7);
    if (resultBusca != NULL){
        printf("\nValor 7 foi encontrado!\n");
    } else {
        printf("\nValor 7 nao foi encontrado\n");
    }
    
    resultBusca = buscaNo(raiz, 5);
    if (resultBusca != NULL){
        printf("\nValor 5 foi encontrado!\n");
    } else {
        printf("\nValor 5 nao foi encontrado\n");
    }

    resultBusca = buscaPai(raiz, 7);
    if (resultBusca != NULL){
        printf("\nPai de 7: %d\n", resultBusca->valor);
    } else {
        printf("\nValor 7 nao foi encontrado\n");
    }

    raiz = removerNo(raiz, 7);
    printf("\nArvore em pre ordem:\n");
    preOrdem(raiz);

    return 0;
}

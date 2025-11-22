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
        }
        return raiz;
    }

    if (novo->valor < pai->valor){
        pai->esq = novo;
    } else {
        pai->dir = novo;
    }
    return raiz;
}

int main(){
    No *raiz = NULL;
    
    return 0;
}

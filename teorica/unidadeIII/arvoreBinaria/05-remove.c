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

// Função para Remover a raiz de uma arvore
No* removeRaiz(No* raiz){
    No* aux = raiz;
    // Verificando se existe nó a esquerda
    if (raiz->esq == NULL){
        aux = raiz->dir;
        free(raiz);
        return aux;
    }
    // Verificando se existe nó a direita
    if (raiz->dir == NULL){
        aux = raiz->esq;
        free(raiz);
        return aux;
    }

    No* p = raiz;
    No* f = raiz->esq;
    // Buscando o maior nó a esqueda da raiz removida 
    while (f->dir != NULL){
        p = f;
        f = f->dir;
    }
    
    // Substituindo a raiz pelo nó novo
    raiz->valor = f->valor;

    // Removendo o nó folha que virou raiz
    if (p->dir == f){
        p->dir = removeRaiz(f);
    } else {
        p->esq = removeRaiz(f);
    }
    return raiz;
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

    return 0;
}

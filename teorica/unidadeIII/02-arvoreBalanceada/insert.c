#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *dir, *esq;
} No;

No* criarNo(int valor){
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->dir=NULL;
    novo->esq=NULL;
    return novo;
}

No* insertArvore(No* raiz, int valor){
    if (raiz == NULL){
        raiz = criarNo(valor);
    } else {
        if (valor < raiz->valor){
            raiz->esq = insertArvore(raiz->esq, valor);
        } else {
            raiz->dir = insertArvore(raiz->dir, valor);
        }
    }
    
    return raiz;
}

void exibirEmOrdem(No* raiz){
    if (raiz == NULL) return;
    exibirEmOrdem(raiz->esq);
    printf("%d ", raiz->valor);
    exibirEmOrdem(raiz->dir);
}

void exibirPreOrdem(No* raiz){
    if (raiz == NULL) return;
    printf("%d ", raiz->valor);
    exibirPreOrdem(raiz->esq);
    exibirPreOrdem(raiz->dir);
}

void exibirPosOrdem(No* raiz){
    if (raiz == NULL) return;
    exibirPosOrdem(raiz->esq);
    exibirPosOrdem(raiz->dir);
    printf("%d ", raiz->valor);
}

int main(){
    No* raiz=NULL;
    
    raiz = insertArvore(raiz, 20);
    insertArvore(raiz, 10);
    insertArvore(raiz, 5);
    insertArvore(raiz, 30);
    insertArvore(raiz, 50);
    insertArvore(raiz, 25);
    insertArvore(raiz, 70);
    
    printf("Exibindo a arvore em pre ordem:\n");
    exibirPreOrdem(raiz);

    printf("\n\nExibindo a arvore em ordem:\n");
    exibirEmOrdem(raiz);

    printf("\n\nExibindo a arvore em pos ordem:\n");
    exibirPosOrdem(raiz);

    return 0;
}

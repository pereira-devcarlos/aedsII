#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esq, *dir;
} No;

// Função para alocar um novo nó na memória
No *alocarNo(int valor){
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
}

// Função para inserir um nó na Arvore (iterativa)
No *inserirNo(No *raiz, No *novo){
    // Caso árvore vazia
    if (raiz == NULL) return novo;

    No *p = NULL;
    No *q = raiz;

    // Percorre a árvore até encontrar a posição correta
    while (q != NULL){
        p = q;
        if (novo->valor < q->valor){
            q = q->esq;
        } else if (novo->valor > q->valor) {
            q = q->dir;
        } else {
            return raiz;
        }
    }

    // Insere o novo nó como filho de p(pai)
    if (novo->valor < p->valor){
        p->esq = novo;
    } else {
        p->dir = novo;
    }
    return raiz;
}

No *buscaNo(No *raiz, int valor){
    // No auxiliar para percorrer a árvore
    No *aux = raiz;
    // Percorre a árvore até encontrar o valor ou chegar ao final
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

    resultBusca = buscaPai(raiz, 2);
    if (resultBusca != NULL){
        printf("\nPai de 5: %d\n", resultBusca->valor);
    } else {
        printf("\nValor 7 nao foi encontrado\n");
    }

    return 0;
}

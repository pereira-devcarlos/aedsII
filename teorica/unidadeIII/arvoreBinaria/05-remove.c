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
    No* tmp = raiz;
    // Verificando se existe nó a esquerda
    if (raiz->esq == NULL){
        tmp = raiz->dir;
        free(raiz);
        return tmp;
    }
    // Verificando se existe nó a direita
    if (raiz->dir == NULL){
        tmp = raiz->esq;
        free(raiz);
        return tmp;
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

// Função para remover um nó qualquer
No* removeNo(No* raiz, int x){
    // verifica se o nó existe na arvore
    No* n = busca(raiz, x);
    if (n){
        // Verifica se o nó possui pai
        No* pai = buscaPai(raiz, x);
        if (pai){
            if (pai->dir == n){
                // Nó a ser removido é filho a direita
                pai->dir = removeRaiz(n);
            }
            else {
                // Nó a ser removido é filho a esquerda
                pai->esq = removeRaiz(n);
            }
        }
        else {
            // Caso não possui um pai, o próprio nó é a raiz 
            raiz = removeRaiz(raiz);
        }
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

    printf("\nPre Ordem:\n");
    preOrdem(raiz);

    // Testando função de remover raiz
    raiz = removeRaiz(raiz);
    printf("\nPre Ordem apos remover a raiz:\n");
    preOrdem(raiz);

    // Testando função de remover nó
    raiz = removeNo(raiz, 8);
    printf("\nPre Ordem apos remover o 8:\n");
    preOrdem(raiz);

    return 0;
}

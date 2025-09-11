#include <stdio.h>
#include <stdlib.h>

// Estrutura da Fila
typedef struct no {
    int chave;
    int valor;

    struct no* ant;
    struct no* prox;
} No;

int main(){
    // Alocando o ptr que irá apontar para a lista
    No* ptlista = (No*) malloc(sizeof(No));
    ptlista->ant = ptlista;
    ptlista->prox = ptlista;

    // Alocando nó para teste de busca
    No* novo = (No*) malloc(sizeof(No));
    novo->chave = 1;
    novo->valor = 5;
    
    novo->ant = ptlista;
    novo->prox = ptlista;
    ptlista->ant = novo;
    ptlista->prox = novo;

    // Alocando nó para teste de busca
    novo = (No*) malloc(sizeof(No));
    novo->chave = 2;
    novo->valor = 10;
    
    novo->ant = ptlista;
    novo->prox = ptlista->prox;
    ptlista->ant->prox = novo;
    ptlista->prox->ant = novo;
    ptlista->ant = novo;

    // Alocando nó para teste de busca
    novo = (No*) malloc(sizeof(No));
    novo->chave = 3;
    novo->valor = 20;

    novo->ant = ptlista->ant;
    novo->prox = ptlista->prox;
    ptlista->ant->prox = novo;
    ptlista->prox->ant = novo;
    ptlista->ant = novo;

    return 0;
}

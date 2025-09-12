#include <stdio.h>
#include <stdlib.h>

// Estrutura para uma 
// Lista Ordenada Duplamente Encadeada Circular
typedef struct no {
    int chave;
    int valor;

    struct no* ant;
    struct no* prox;
} No;

// Função de busca 
No* busca(No* ptlista, int x){
    No* ultimo = ptlista->ant;

    if (ultimo != ptlista && x <= ultimo->chave){
        // Pont recebendo o 1° elemento da lista
        No* pont = ptlista->prox;

        while (pont->chave < x){
            pont = pont->prox;
        }
        return pont;
    }
    return ptlista;
}

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

    // Testando a função de busca
    No* busc = busca(ptlista, 1);
    if(busc->chave == 1){
        printf("\nElemento 1 encontrado!!");
    } else {
        printf("\nElemento 1 nao encontrado!!");
    }

    busc = busca(ptlista, 3);
    if(busc->chave == 3){
        printf("\nElemento 3 encontrado!!");
    } else {
        printf("\nElemento 3 nao encontrado!!");
    }

    busc = busca(ptlista, 4);
    if(busc->chave == 4){
        printf("\nElemento 4 encontrado!!");
    } else {
        printf("\nElemento 4 nao encontrado!!");
    }

    // Liberando a memória
    free(ptlista);
    free(novo);

    return 0;
}

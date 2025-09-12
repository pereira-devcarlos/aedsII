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

/** Função de busca
 * Retorno:
 *  - caso o x > ultimo->chave da lista:
 *      --> retorna ptlista
 *  - caso o x <= ultimo->chave:
 *      --> retorna o endereço do nó que a chave >= x;
 */
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

/** Função de inserção
 * Retorno:
 *  - caso ocorra a inserção:
 *      --> retorna NULL
 *  - caso não ocorra a inserção:
 *      --> retorna o endereço retornado pela função buscar
 */
No* inserir(No *ptlista, No *novo){
    No *pont = busca(ptlista, novo->chave);

    // Verifica se a lista está vazia ou
    // Se a chave do nó a ser inserido não existir na lista
    if (pont == ptlista || novo->chave != pont->chave){
        novo->prox = pont;
        novo->ant = pont->ant;
        pont->ant->prox = novo;
        pont->ant = novo;
        return NULL;
    }

    // Caso a chave do nó a ser inserido já existir na lista
    return pont;
}

/** Função de Remoção
 * Retorno:
 *  - caso ocorra a remoção:
 *      --> endereço do nó removido
 *  - caso não ocorra a remoção (nó não encontrado):
 *      --> NULL
 */
No* remover(No *ptlista, int x){
    No* pont = busca(ptlista, x);

    if (pont != ptlista && pont->chave == x){
        pont->ant->prox = pont->prox;
        pont->prox->ant = pont->ant;
        return pont;
    }
    return NULL;
}

int main(){
    // Alocando o ptr que irá apontar para a lista
    No* ptlista = (No*) malloc(sizeof(No));
    ptlista->ant = ptlista;
    ptlista->prox = ptlista;

    // Alocando nó para teste de inserção
    No* novo = (No*) malloc(sizeof(No));
    novo->chave = 1;
    novo->valor = 5;
    
    No* insere = inserir(ptlista, novo);
    if (insere == NULL){
        printf("\nElemento inserido: chave=%d, valor=%d", novo->chave, novo->valor);
    } else {
        printf("\nErro ao inserir o elemento: chave=%d, valor=%d", novo->chave, novo->valor);

    }

    // Alocando nó para teste de inserção
    novo = (No*) malloc(sizeof(No));
    novo->chave = 2;
    novo->valor = 10;
    
    insere = inserir(ptlista, novo);
    if (insere == NULL){
        printf("\nElemento inserido: chave=%d, valor=%d", novo->chave, novo->valor);
    } else {
        printf("\nErro ao inserir o elemento: chave=%d, valor=%d", novo->chave, novo->valor);
    }

    // Testando a função de remoção
    No* rem = remover(ptlista, 2);
    if (rem != NULL){
        printf("\nElemento removido: chave=%d, valor=%d", rem->chave, rem->valor);
        free(rem);
    } else {
        printf("\nErro: nao possui no a ser removido com chave=%d", 2);
    }

    // Alocando nó para teste de inserção
    novo = (No*) malloc(sizeof(No));
    novo->chave = 2;
    novo->valor = 20;

    insere = inserir(ptlista, novo);
    if (insere == NULL){
        printf("\nElemento inserido: chave=%d, valor=%d", novo->chave, novo->valor);
    } else {
        printf("\nErro ao inserir o elemento: chave=%d, valor=%d", novo->chave, novo->valor);
    }

    // Testando a função de remoção
    rem = remover(ptlista, 3);
    if (rem != NULL){
        printf("\nElemento removido: chave=%d, valor=%d", rem->chave, rem->valor);
        free(rem);
    } else {
        printf("\nErro: nao possui no a ser removido com chave=%d", 3);
    }

    // Liberando a memória
    free(ptlista);
    free(novo);

    return 0;
}

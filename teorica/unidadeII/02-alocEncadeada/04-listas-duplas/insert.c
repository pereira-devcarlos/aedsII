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
No *inserir(No *ptlista, No *novo){
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

    // Liberando a memória
    free(ptlista);
    free(novo);

    return 0;
}

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
 *      --> retorna o endereço do nó removido
 *  - caso não ocorra a remoção (nó não encontrado):
 *      --> retorna NULL
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

void exibirMenu(){
    printf("\n|||||||||||> Menu <|||||||||||");
    printf("\n[1]-Inserir um no");
    printf("\n[2]-Remover um no");
    printf("\n[3]-Buscar um no");
    printf("\n[0]-Encerrar o programa");
    printf("\n-Digite a opcao desejada: ");
}

int main(){
    // Criando ptr que irá apontar para a lista
    No* ptlista = (No*) malloc(sizeof(No));
    ptlista->ant = ptlista;
    ptlista->prox = ptlista;

    int opcao = -1;
    while (opcao != 0){
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
        {
            // Alocando nó para a inserção
            No* novo = (No*) malloc(sizeof(No));
            
            printf("\nDigite a chave do seu no: ");
            scanf("%d", novo->chave);
            printf("\nDigite o valor do seu no: ");
            scanf("%d", novo->valor);
            
            No* insere = inserir(ptlista, novo);
            if (insere == NULL){
                printf("\nElemento inserido: chave=%d, valor=%d", novo->chave, novo->valor);
            } else {
                printf("\nErro ao inserir o elemento: chave=%d, valor=%d", novo->chave, novo->valor);
            }
            break;
        }
        case 2:
        {
            int chaveRemover;
            printf("\nDigite a chave do no que deseja remover: ");
            scanf("%d", &chaveRemover);

            No* rem = remover(ptlista, chaveRemover);
            if (rem != NULL){
                printf("\nElemento removido: chave=%d, valor=%d", rem->chave, rem->valor);
                free(rem);
            } else {
                printf("\nErro: nao possui no a ser removido com chave=%d", chaveRemover);
            }
            break;
        }
        case 3:
        {
            int chaveBusca;
            printf("\nDigite a chave do no a ser buscado: ");
            scanf("%d", &chaveBusca);

            No* buscar = busca(ptlista, chaveBusca);
            if (buscar != ptlista && buscar->chave == chaveBusca){
                printf("\nElemento encontrado: chave=%d, valor=%d", buscar->chave, buscar->valor);
            } else if (buscar != ptlista && buscar->chave != chaveBusca){
                printf("\nElemento com a chave=%d nao foi encontrado!", chaveBusca);
            } else {
                printf("\nErro: lista vazia!");
            }
            break;
        }
        case 0:
            printf("\nEncerrando o programa...");
            break;
        default:
            printf("\nErro: opcao invalida!");
            break;
        }
    }

    // Liberando a memória
    free(ptlista);
    
    return 0;
}

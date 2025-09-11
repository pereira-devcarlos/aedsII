#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include <stdbool.h>
#include "fila.h"

// Nó da fila
typedef struct no {
    int valor;
    struct no* prox;
} No;

// Estrutura da fila
struct fila { 
	No* inicio; 
	No* fim; 
	int tamanhoAtul; 
	No* items; 
};

struct fila* criar_fila() { 
	// Aloca a estrutura de dados fila
    struct fila* fila = (struct fila*) malloc(sizeof(struct fila)); 
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanhoAtul = 0; 
    fila->items = NULL; 
    // Retorna a fila
	return fila; 
} 

bool ehVazia(struct fila* fila) { 
	// Se o início == NULL, então a fila é vazia
    if (fila->inicio == NULL) {
        return (true);
    } 
    return (false);
} 

void push(struct fila* fila, int item) { 
    // Alocação do nó a ser inserido na fila
    No* insere = (No*) malloc(sizeof(No));
    insere->valor = item;
    insere->prox = NULL;

    if (ehVazia(fila)) { 
        fila->inicio = insere;
        fila->fim = insere;
        fila->items = insere;
        return;
    }
    fila->fim->prox = insere;
    fila->fim = insere;
    fila->tamanhoAtul++;
}


No* pop(struct fila* fila) { 
    // Nó que será retornado após a remoção da fila
    No* rem;

    if (ehVazia(fila)) {
        printf("\nFila vazia. Impossível remover elementos");
        return NULL; 
    } else {
        rem = fila->inicio;
        fila->inicio = fila->inicio->prox; 

        if (fila->inicio == fila->fim) {
            // Último elemento removido
            fila->inicio = NULL;
            fila->fim = NULL;
        } 
    }

    return rem;
} 

No* obtem_elemento(struct fila* fila) { 
	// Se a fila estiver vazia, não tem como obter nenhum elemento
    if (ehVazia(fila)) {
		printf("\nFila vazia. Impossível obter elementos");
        return NULL; 
    }
    // Retorna o elemento do início da fila
	return fila->inicio; 
} 


int main() { 
    int val, n;
    bool aux;
    // Criar fila
    struct fila* fila = criar_fila();
    do {
        printf("\n************************* MENU ************************");
	    printf("\n1. Push");
	    printf("\n2. Pop");
	    printf("\n3. Obtém elemento");
	    printf("\n4. Fila vazia?");
        printf("\n5. Fila cheia?");
	    printf("\n6. Sair");
	    printf("\n Digite sua escolha : ");
	    scanf("%d",&n);
	    switch(n) {
            case 1: {
		        printf("\nDigite o valor ");
                scanf("%d",&val);
                inserir->items = val;

                push(fila, inserir);
                break;
            }
            case 2: 
                printf("\nElemento retirado : %d",pop(fila));
                break;
            case 3: 
                if (ehVazia(fila)){
                    printf("\nFila vazia. Impossível obter elementos");
                } else {
                    printf("\nElemento do início: %d",obtem_elemento(fila));
                }
                
                break;
            case 4: 
                aux = ehVazia(fila);
                if (aux) {
                    printf("\nFila vazia");
                } else {
                    printf("\nFila não está vazia");
                }
                break;
            case 5: 
                aux = ehCheia(fila);
                if (aux) {
                    printf("\nFila cheia");
                } else {
                    printf("\nFila não está cheia");
                }
                break;         
            case 6:
                return (1);
                break;
            default: printf("\nOpção errada!");
                break;
        }
	} while(1);
    
    return (0);
 }





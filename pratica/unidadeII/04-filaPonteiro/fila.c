#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include <stdbool.h>
#include "fila.h"

// Estrutura da fila
struct fila { 
	int * inicio; 
	int * fim; 
	int tamanhoAtul; 
	No* items; 
};

// Nó da fila
typedef struct no {
    int valor;
    struct no* prox;
} No;

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

void push(struct fila* fila, struct fila* inserir) { 
    if (ehVazia(fila)) { 
        fila->inicio = inserir;
        fila->fim = inserir;
        fila->items = inserir->items; // Insere o primeiro elemento
        return;
    }
    fila->fim->prox = inserir;
    fila->fim = inserir;
}


struct fila* pop(struct fila* fila) { 
    struct fila* rem;
    if (ehVazia(fila)) {
        printf("\nFila vazia. Impossível remover elementos");
        return -1; 
    } else {
        rem = fila;
        fila->inicio = fila->inicio->prox; 

        if (fila->inicio == fila->fim) {
            // Último elemento removido
            fila->inicio = NULL;
            fila->fim = NULL;
        } 
    }

    return rem;
} 

struct fila* obtem_elemento(struct fila* fila) { 
	// Se a fila estiver vazia, não tem como obter nenhum elemento
    if (ehVazia(fila)) {
		printf("\nFila vazia. Impossível obter elementos");
        return -1; 
    }
    // Retorna o elemento do início da fila
	return fila->inicio; 
} 


int main() { 
    int val, n;
    bool aux;
    // Cria fila com 5 posições
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
                struct fila* inserir = criar_fila();
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





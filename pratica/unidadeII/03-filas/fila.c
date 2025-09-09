#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include <stdbool.h>
#include "fila.h"

struct fila { 
	int inicio; 
	int fim; 
	int tamanho; 
	int* items; 
}; 

struct fila* criar_fila(int tamanho) { 
	// Aloca a estrutura de dados fila
    struct fila* fila = (struct fila*)malloc(sizeof(struct fila)); 
	// Armazena o tamanho que ela foi criada
    fila->tamanho = tamanho; 
    // Diz que não existe nenhum elemento no início e no fim
    fila->inicio = -1;
    fila->fim = -1;
    // Aloca o vetor de items utilizando o tamanho passado para a função
    fila->items = (int*)malloc(fila->tamanho * sizeof(int)); 
    // Retorna a fila
	return fila; 
} 

bool ehCheia(struct fila* fila) { 
    // Se fim == tamanho - 1, quer dizer que a fila é cheia
    int prov = (fila->fim + 1) % fila->tamanho;
    if (prov == fila->inicio) {
        return (true);
    }
    // Caso contrário, ela não está cheia
    return (false);
} 

bool ehVazia(struct fila* fila) { 
	// Se o início == -1, então a fila é vazia
    // Verificar que isto é verdade na criação da fila
    if (fila->inicio == -1) {
        return (true);
    } 
    return (false);
} 

void push(struct fila* fila, int item) { 
    if (ehCheia(fila)) {
        printf("\nFila cheia. Impossível inserir elementos");
        return; 
    } else if (ehVazia(fila)) { 
        fila->inicio = 0;
        fila->fim = 0;
        fila->items[fila->fim] = item; // Insere o primeiro elemento
        return;
    }
    fila->fim = (fila->fim + 1) % fila->tamanho;
    fila->items[fila->fim] = item; 
} 


int pop(struct fila* fila) { 
    if (ehVazia(fila)) {
        printf("\nFila vazia. Impossível remover elementos");
        return -1; 
    }
    int item = fila->items[fila->inicio];
    if (fila->inicio == fila->fim) {
        // Último elemento removido
        fila->inicio = -1;
        fila->fim = -1;
    } else {
        fila->inicio = (fila->inicio + 1) % fila->tamanho;
    }
    return item;
} 

int obtem_elemento(struct fila* fila) { 
	// Se a fila estiver vazia, não tem como obter nenhum elemento
    if (ehVazia(fila)) {
		printf("\nFila vazia. Impossível obter elementos");
        return INT_MIN; 
    }
    // Retorna o elemento do início da fila
	return fila->items[fila->inicio]; 
} 


int main() { 
    int val, n;
    bool aux;
    // Cria fila com 5 posições
    struct fila* fila = criar_fila(5);
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
            case 1: 
		        printf("\nDigite o valor ");
                scanf("%d",&val);
                push(fila , val);
                break;
            case 2: 
                printf("\nElemento retirado : %d",pop(fila));
                break;
            case 3: 
                printf("\nElemento do início: %d",obtem_elemento(fila));
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





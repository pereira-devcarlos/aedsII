#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    int valor;
    struct no* prox;
} No;

// Função de inserção em uma pilha
void insertPilha(No* inserir, No* topo){
    inserir->prox = topo;
    topo = inserir;
}

int main(){
    No* topo = NULL;

    // Nó alocado para a inserção
    No * inserir = (No*) malloc(sizeof(No));

    printf("\nDigite a chave do no: ");
    scanf("%d", &inserir->chave);      
    printf("\nDigite o valor do no: ");
    scanf("%d", &inserir->valor);
    inserir->prox = NULL;

    insertPilha(inserir, topo);
    printf("\nInsercao realizada com sucesso -> chave: %d, valor: %d\n", inserir->chave, inserir->valor);

    return 0;
}

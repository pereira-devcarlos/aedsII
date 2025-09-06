#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    int valor;
    struct no* prox;
} No;

// Função para inserir um no em uma pilha
void insertPilha(No* inserir, No** topo){
    inserir->prox = *topo;
    *topo = inserir;
}

// Função para remover um no de uma pilha
No * removePilha(No* topo){
    No * retorno = NULL;
    if (topo != NULL){
        retorno = topo;
        topo = topo->prox;
    }
    return retorno;
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

    insertPilha(inserir, &topo);
    printf("\nInsercao realizada com sucesso -> chave: %d, valor: %d\n", inserir->chave, inserir->valor);

    // Testando a remoção
    No* teste = removePilha(topo);
    if (teste != NULL){
        printf("\nNo removido com sucesso-> chave:%d, valor:%d\n", teste->chave, teste->valor);
    } else {
        printf("\nErro ao remover um no, pilha vazia!\n");
    }
    

    return 0;
}

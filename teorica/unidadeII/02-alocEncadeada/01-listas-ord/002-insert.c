#include<stdio.h>
#include<stdlib.h>

typedef struct no {
    // Usada para indexar conteúdo.
    int chave;
    // Guardar ex: info. útil.
    int valor;

    struct no* prox;
} No ;

// Variavel global já que será utilizadas varias vezes
No * ptlista;

// Função de Busca Encadeada
void busca(int x, No ** ant, No ** pont){
    *ant = ptlista;
    *pont = NULL;
    No * ptr = ptlista->prox;

    while (ptr != NULL){
        if (ptr->chave < x){
            *ant = ptr;
            ptr = ptr->prox;
        } else {
            if (ptr->chave == x){
                *pont = ptr;
            }
            ptr = NULL;
        }
    }
}

// Função de inserção
int insert(No * inserir){
    int re = -1;
    No * ant;
    No * pont;
    busca(inserir->chave, &ant, &pont);
    if (pont == NULL){
        inserir->prox = ant->prox;
        ant->prox = inserir;
        re = 0;
    }
    return re;
}

void main(){
    // Inicia ptlista apontadando para null
    ptlista = (No*) malloc(sizeof(No));
    ptlista->prox = NULL;

    // Varáveis para manipular a lista
    No * ant; // Armazena o no anterior
    No * pont; // Retorno das funções

    No * inserir = (No*) malloc(sizeof(No));
    inserir->chave = 1;
    inserir->valor = 3;
    inserir->prox = NULL;
    int teste = insert(inserir);

    inserir = (No*) malloc(sizeof(No));
    inserir->chave = 2;
    inserir->valor = 4;
    inserir->prox = NULL;
    teste = insert(inserir);

    int chave_procurar = 2;
    printf("elemento sendo buscado: %d\n", chave_procurar);

    busca(chave_procurar, &ant, &pont);
    if(pont != NULL){
        printf("Elemento encontrado!\n\n");
    }else{
        printf("Elemento não encontrado!\n\n");
    }


    chave_procurar = 4;
    printf("elemento sendo buscado: %d\n", chave_procurar);

    busca(chave_procurar, &ant, &pont);
    if(pont != NULL){
        printf("Elemento encontrado!\n\n");
    }else{
        printf("Elemento não encontrado!\n\n");
    }
    
    //TODO:
    // - implementar a remoção
    // - implementar a impressão
    // - implementar a liberação de memória (ao encerrar)
    // - ajustar o código de modo a ficar "utilizável",
    // com menu para buscar, inserir, remover, imprimir e encerrar.
}
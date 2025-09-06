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

// Função de remoção
No * remover(int x){
    No * ant;
    No * pont;
    busca(x, &ant, &pont);
    if (pont != NULL){
        ant->prox = pont->prox;
        return pont;
    }
    return NULL;
} 

void menu(){
    printf("\n************ MENU ************");
    printf("\n[1]-Buscar um no");
    printf("\n[2]-Inserir um no");
    printf("\n[3]-Remover um no");
    printf("\n[0]-Encerrar programa");
    printf("\nDigite a opcao que deseja: ");
}

void main(){
    // Inicia ptlista apontadando para null
    ptlista = (No*) malloc(sizeof(No));
    ptlista->prox = NULL;

    // Varáveis para manipular a lista
    No * ant; // Armazena o no anterior
    No * pont; // Retorno das funções

    int opcao = -1;
    while (opcao != 0){
        menu();
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:{
            int chaveProcurar;
            printf("\nDigite a chave que deseja buscar: ");
            scanf("%d", &chaveProcurar);
            
            busca(chaveProcurar, &ant, &pont);
            if(pont != NULL){
                printf("\nElemento %d encontrado!\n", chaveProcurar);
            }else{
                printf("\nElemento %d nao encontrado!\n", chaveProcurar);
            }
            break;
        }
        case 2:{
        }
        case 0:
            printf("\nEncerrando programa...");
            break;
        default:
            printf("\nErro: opcao invalida!");
            break;
        }
    }


    No * rem = remover(1);
    if (rem == NULL){
        printf("\nErro ao remover no");
    } else {
        printf("\nNo com a chave %d foi removido com sucesso!\n", rem->chave);
    }

    //TODO:
    // - implementar a remoção   (Realizada com sucecsso!)
    // - implementar a impressão
    // - implementar a liberação de memória (ao encerrar)
    // - ajustar o código de modo a ficar "utilizável",
    // com menu para buscar, inserir, remover, imprimir e encerrar.
}
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
No * removePilha(No** topo){
    No * retorno = NULL;
    if (*topo != NULL){
        retorno = *topo;
        *topo = (*topo)->prox;
    }
    return retorno;
}

void exibirPilha(No* topo){
    if (topo == NULL){
        printf("\nLista Vazia!\n");
    } else {
        while (topo != NULL){
            printf("\nChave: %d, Valor: %d", topo->chave, topo->valor);
            topo = topo->prox;
        }
        printf("\n");
    }
}

void menu(){
    printf("\n************ MENU ************");
    printf("\n[1]-Inserir um no");
    printf("\n[2]-Remover um no");
    printf("\n[3]-Imprimir pilha");
    printf("\n[0]-Encerrar programa");
    printf("\nDigite a opcao que deseja: ");
}

int main(){
    No* topo = NULL;  

    int opcao = -1;
    while (opcao != 0){
        menu();
        scanf("%d", &opcao);

        switch (opcao){
        case 1:{
            // Nó alocado para a inserção
            No * inserir = (No*) malloc(sizeof(No));

            printf("\nDigite a chave do no: ");
            scanf("%d", &inserir->chave);      
            printf("\nDigite o valor do no: ");
            scanf("%d", &inserir->valor);
            inserir->prox = NULL;
            
            insertPilha(inserir, &topo);
            printf("\nInsercao realizada com sucesso -> chave: %d, valor: %d\n", inserir->chave, inserir->valor);
            break;
        }
        case 2:{
            // Nó para armazenar o retorno da função remover
            No* teste = removePilha(&topo);
            if (teste != NULL){
                printf("\nNo removido com sucesso-> chave:%d, valor:%d\n", teste->chave, teste->valor);
                free(teste);
            } else {
                printf("\nErro ao remover um no, pilha vazia!\n");
            }
            break;
        }
        case 3:
            exibirPilha(topo);
            break;
        case 0:
            printf("\nEncerrando programa...\n");
            break;
        default:
            printf("\nErro: opcao invalida!\n");
            break;
        }
    }

    return 0;
}

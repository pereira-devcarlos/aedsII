#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    int valor;
    struct no* prox;
} No;

void insertFila(No * insere, No **inicio, No **fim){
    if (*fim != NULL){
        (*fim)->prox= insere;
    } else {
        *inicio = insere;
    }
    *fim = insere;
}

No* removeFila(No **inicio, No **fim){
    No * retorno = NULL;
    if (*inicio != NULL){
        retorno = *inicio;
        *inicio = (*inicio)->prox;

        // Caso a fila ficar vazia
        if (*inicio == NULL){
            *fim = NULL;
        }
    }
    return retorno;
}

void listarFila(No *inicio, No *fim){
    if(inicio != NULL){
        printf("\nFila encadeada:");
        for (int i = 1; inicio!= NULL; i++){
            printf("\nPosicao %d: chave=%d, valor=%d", i, inicio->chave, inicio->valor);
            inicio = inicio->prox;
        }
        printf("\n");
    } else {
        printf("\nFila Vazia!\n");
    }
}

void menu(){
    printf("\n|||||||||| Menu ||||||||||");
    printf("\n[1]-Inserir no na fila");
    printf("\n[2]-Remover no na fila");
    printf("\n[3]-Listar fila");
    printf("\n[0]-Encerrar programa");
    printf("\nDigite a opcao desejada: ");
}

int main(){
    No * inicio = NULL;
    No * fim = NULL;

    int opcao = -1;
    while (opcao != 0){
        menu();
        scanf("%d", &opcao);

        switch (opcao){
        case 1:{
            // Alocando um nó na mémoria
            No* insere = (No*) malloc(sizeof(No));

            // Entrada de dados do usuário
            printf("\nDigite a chave que deseja inserir: ");
            scanf("%d", &insere->chave);
            printf("\nDigite o valor que deseja inserir: ");
            scanf("%d", &insere->valor);
            insere->prox= NULL;
            
            // Chamada da função de inserção
            insertFila(insere, &inicio, &fim);
            printf("\nNo inserido: chave=%d, valor=%d\n", insere->chave, insere->valor);            
            break;
        }
        case 2:{
            No* liberar = removeFila(&inicio, &fim);
            // Verificar se possui algo a ser removido da fila
            if (liberar != NULL){ 
                printf("\nRemovido: chave=%d, valor=%d\n", liberar->chave, liberar->valor);
                free(liberar);
            } else {
                printf("\nFila Vazia! Nada a ser removido!\n");
            }
            break;
        }
        case 3:{
            // Exibir todos os nós da fila
            listarFila(inicio, fim);

            break;
        }
        case 0:
            printf("\nEncerrando programa...");
            break;
        default:
            printf("\nErro: opcao invalida!");
            break;
        }
    }

    return 0;
}

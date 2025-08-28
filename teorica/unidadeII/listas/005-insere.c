#include <stdio.h>
#include <stdlib.h>

int busca(int v[], int x, int tam){
    int i = 0;
    while (v[i] != x){
        i++;
    }
    if (i+1 >= tam + 1){
        // Retorna -1 caso o elemento nao seja encontrado
        return -1;
    } else {
        // Retorna a posição do elemento encontrado
        return i+1;
    }
    
}

int insere(int v[], int *n, int tam, int ins){
    if (*n<tam-1){
        if (busca(v, ins, tam)==-1){
            // Retorna caso o tamanho seja preenchido + 1
            v[*n+1] = ins;
            (*n)++;
            return *n;
        }
        // Retorna -1 caso o elemento já possui no vetor
        return -1;
    }
    // Retorna -2 caso o vetor estiver cheio
    return -2;
}

int main(){
    int n=7;
    int vetor[10] = {1, 2, 3, 4, 5, 9, 12, 15};

    int opcao=1;
    while (opcao!=0){
        printf("\n====== Menu de Opções ======\n");
        printf("[1]-Buscar elemento\n");
        printf("[2]-Inserir elemento\n");
        printf("[0]-Sair\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);
    
        switch (opcao){
        case 1:
            printf("\nDigite o numero que deseja buscar: ");
            scanf("%d", &vetor[9]);
            
            int pos = busca(vetor, vetor[9], 9);
    
            if (pos == -1){
                printf("\nErro: neste vetor nao possui o numero %d\n", vetor[9]);
            } else {
                printf("\nO numero %d esta na posicao %d\n", vetor[9], pos);
            }
            break;
        case 2:
            printf("\nDigite o numero que deseja inserir: ");
            scanf("%d", &vetor[9]);    
    
            int ins = insere(vetor, &n, 9, vetor[9]);
    
            if (ins == -2){
                printf("\nErro: Vetor não possui espaço para a inserção\n");
            } else if (ins == -1){
                printf("\nErro: o elemento %d já possui nesse vetor.\n", vetor[9]);
            } else {
                printf("\nO numero %d foi inserido com sucesso!\n", vetor[9]);
            }
            break;
        case 0:
            printf("\nEncerrando o programa...\n");
            break;
        default:
            printf("\nErro: opção invalida.\n");
            break;
        }
    }

    return 0;
}
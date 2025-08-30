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

int remove_elemento(int v[], int *n, int x, int tam){
    if (*n != 0){ // Verifica se o vetor não está vazio
        int pos = busca(v, x, tam);
        // Verifica se existe o elemento a ser removido
        if (pos != -1){ 
            int i = pos - 1; // converter para índice 0
            for (; i < *n - 1; i++){
                v[i] = v[i+1];
            }
            v[*n]=-1;
            (*n)--;
            return 1; // sucesso
        }
        return 0;
    }
    return -1; // falha
}

int main(){
    int n=7;
    int vetor[10] = {1, 2, 3, 4, 5, 9, 12, 15};

    int opcao=1;
    while (opcao!=0){
        printf("\n====== Menu de Opções ======\n");
        printf("[1]-Buscar elemento\n");
        printf("[2]-Inserir elemento\n");
        printf("[3]-Remover elemento\n");
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

        case 3:
            printf("\nDigite o numero a ser removido: ");
            scanf("%d", &vetor[9]);

            int rem = remove_elemento(vetor, &n, vetor[9], 9);

            if (rem == 1){
                printf("\nO numero %d foi removido com sucesso!\n", vetor[9]);
            } else if (rem == 0){
                printf("\nErro: numero %d não existe nesse vetor\n", vetor[9]);
            } else {
                printf("\nErro: vetor está vazio\n");
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
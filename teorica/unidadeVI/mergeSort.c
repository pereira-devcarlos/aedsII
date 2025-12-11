#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void merge(int v[], int inicio, int meio, int fim) {
    // Obtém a quantidade de elementos de cada lado
    int quantEsq = meio - inicio + 1;
    int quantDir = fim - meio;

    // Aloca e armazena os elementos em 2 vetores
    int *Esq = (int*) malloc(quantEsq * sizeof(int));
    int *Dir = (int*) malloc(quantDir * sizeof(int));
    for (int i = 0; i < quantEsq; i++){
        Esq[i] = v[inicio + i];
    }
    for (int j =0; j < quantDir; j++){
        Dir[j] = v[meio + 1 + j];
    }
    
    // Incializando variaveis para percorrer os vetores
    int i=0;        // Vetor a Esquerda
    int j=0;        // Vetor a Direita
    int k=inicio;   // Vetor final (fusão)

    // Loop comparando os valores
    while (i < quantEsq && j < quantDir){
        if (Esq[i] <= Dir[j]){
            v[k++] = Esq[i++];
        } else {
            v[k++] = Dir[j++];
        }
    }

    // Loop se caso sobrar valores a Esquerda
    while (i < quantEsq){
        v[k++] = Esq[i++];
    }

    // Loop se caso sobrar valores a Direita
    while (j < quantDir){
        v[k++] = Dir[j++];
    }
}


void mergeSort(int v[], int in, int fim){
    if (in < fim){
        int meio = (in + fim)/2;
        // Recursividade para repartir o vetor
        mergeSort(v, in, meio);
        mergeSort(v, meio+1, fim);
        
        // Função que irá ordenar o juntar as repartições
        merge(v, in, meio, fim);
    }
}

int main(){
    int v[TAM] = {11, 2, 3, 8, 4, 4, 6, 9, 2, 7};

    // Mostrar vetor antes da ordenação
    printf("Vetor antes da ordenacao:\n");
    for (int i = 0; i < TAM; i++){
        printf("%d ", v[i]);
    }

    // Ordenar o vetor usando Merge Sort
    mergeSort(v, 0, TAM-1);

    // Mostrar vetor após a ordenação
    printf("\nVetor apos a ordenacao:\n");
    for (int i = 0; i < TAM; i++){
        printf("%d ", v[i]);
    } 
    
    return 0;
}

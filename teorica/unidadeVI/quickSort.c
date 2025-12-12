#include <stdio.h>
#include <stdlib.h>
#define TAM 10

int particao(int v[], int in, int fim){
    // Pivo sempre será no fim da repartição
    int pivo = v[fim];
    int aux;    // Var auxiliar para fazer os swap's
    int i = in - 1; // Indice onde será colocados: valores < pivo

    // Loop separar os valores < pivo
    for (int j = in; j < fim; j++){
        if (v[j] < pivo){
            i++;
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
    }

    // Swap para inserir o pivo no lugar ideal val < p < val
    aux = v[i+1];
    v[i+1] = v[fim];
    v[fim] = aux;

    // Retornar a pos do pivo
    return i + 1;
}

void quickSort(int v[], int in, int fim){
    if(in < fim){
        int p = particao(v, in, fim);
        quickSort(v, in, p -1);
        quickSort(v, p + 1, fim);
    }
}

int main(){
    int v[TAM] = {11, 2, 3, 8, 1, 4, 6, 9, 5, 7};

    // Mostrar vetor antes da ordenação
    printf("Vetor antes da ordenacao:\n");
    for (int i = 0; i < TAM; i++){
        printf("%d ", v[i]);
    }

    // Ordenar o vetor usando Quick Sort
    quickSort(v, 0, TAM-1);

    // Mostrar vetor após a ordenação
    printf("\nVetor apos a ordenacao:\n");
    for (int i = 0; i < TAM; i++){
        printf("%d ", v[i]);
    } 

    return 0;
}

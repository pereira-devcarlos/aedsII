#include <stdio.h> 
#include <stdlib.h> 
#define TAM 10

void heapfy(int v[], int i, int tam){
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < tam && v[maior] < v[esq]) maior = esq;
    if (dir < tam && v[maior] < v[dir]) maior = dir;
    
    if (maior != i){
        int aux = v[i];
        v[i] = v[maior];
        v[maior] = aux;
        heapfy(v, maior, tam);
    }
}

void heapSort(int v[], int tam){
    for (int i = tam/2 - 1; i >= 0; i--){
        heapfy(v, i, tam);
    }
    
    for (int i = tam - 1; i > 0; i--){
        int aux = v[0];
        v[0] = v[i];
        v[i] = aux;

        heapfy(v, 0, i);
    }
}

void imprimir(int v[], int tam){
    for (int i = 0; i < tam; i++){
        printf("[%d]", v[i]);
    }
}

int main() { 
    int v[TAM] = {11, 2, 3, 8, 1, 4, 6, 9, 5, 7};
    printf("\nVetor antes do HeapSort:\n");
    imprimir(v, TAM);

    heapSort(v, TAM);
    printf("\nVetor apos o HeapSort:\n");
    imprimir(v, TAM);

    return 0;
}
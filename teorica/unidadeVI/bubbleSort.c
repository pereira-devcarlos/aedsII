#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM 5
int contador = 0;

void swap(int *v1, int *v2){
    int aux = *v1;
    *v1 = *v2;
    *v2 = aux;
}

void bubbleSort(int v[]){
    int aux;
    bool trocou = true; // Flag para verificar se houve troca na passagem
    for (int i = TAM-1; i > 0 && trocou; i--){
        trocou = false;
        for (int j = 0; j < i; j++){
            if (v[j] > v[j+1]){
                swap(&v[j], &v[j+1]);

                trocou = true;
            }
        }
        // Contabiliza uma passagem completa pelo vetor
        // Apenas para fins de análise de desempenho
        contador++;
    }
}

int main(){
    int v[TAM] = {11, 2, 3, 8, 4};
    printf("Vetor antes da ordenacao:\n");
    for (int i = 0; i < TAM; i++){
        printf("%d ", v[i]);
    }
    
    bubbleSort(v);
    printf("\nVetor apos a ordenacao:\n");
    for (int i = 0; i < TAM; i++){
        printf("%d ", v[i]);
    } 
    printf("\nFoi preciso percorrer %dx o vetor para ordernar", contador);
    
    return 0;
}

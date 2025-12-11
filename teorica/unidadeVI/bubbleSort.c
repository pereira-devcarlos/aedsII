#include <stdio.h>
#include <stdlib.h>

#define TAM 5
int contador = 0;

void bubbleSort(int v[]){
    int aux;
    int trocou = 1; // Flag para verificar se houve troca na passagem
    for (int i = TAM-1; i > 0 && trocou; i--){
        trocou = 0;
        for (int j = 0; j < i; j++){
            if (v[j] > v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;

                trocou = 1;
            }
        }
        // Contabiliza uma passagem completa pelo vetor
        // Apenas para fins de análise de desempenho
        contador++;
    }
}

int main(){
    int v[TAM] = {1, 2, 3, 8, 4};
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

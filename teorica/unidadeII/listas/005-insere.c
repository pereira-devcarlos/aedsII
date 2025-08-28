#include <stdio.h>
#include <stdlib.h>

int busca(int v[], int x, int tam){
    int i = 0;
    while (v[i] != x){
        i++;
    }
    if (i+1 >= tam + 1){
        return -1;
    } else {
        return i+1;
    }
    
}

int main(){
    int vetor[10] = {1, 2, 3, 4, 5, 9, 12, 15, 16, 18};

    printf("Digite o numero que deseja buscar: ");
    scanf("%d", &vetor[9]);

    int pos = busca(vetor, vetor[9], 9);

    if (pos == -1){
        printf("\nErro: neste vetor nao possui o numero %d\n", vetor[9]);
    } else {
        printf("\nO numero %d esta na posicao %d\n", vetor[9], pos);
    }

    return 0;
}
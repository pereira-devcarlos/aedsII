#include <stdio.h>
#define TAM 10

int busca(int v[], int x){
    int i = 0;
    while (v[i] != x){
        i++;
    }
    if (i+1 >= TAM + 1){
        return -1;
    } else {
        return i+1;
    }
    
}

int main(){
    int vetor[TAM + 1] = {1, 2, 3, 4, 5, 9, 12, 15, 16, 18, 0};

    printf("Digite o numero que deseja buscar: ");
    scanf("%d", &vetor[10]);
    
    int pos = busca(vetor, vetor[10]);

    if (pos == -1){
        printf("\nErro: neste vetor nao possui o numero %d", vetor[10]);
    } else {
        printf("\nO numero %d esta na posicao %d", vetor[10], pos);
    }

    return 0;
}

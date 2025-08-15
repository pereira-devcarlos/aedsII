#include <stdio.h>
#define TAM 10

int buscaOrd(int v[], int x){
    v[TAM] = x;

    int i = 0;
    while (v[i] < x){
        i++;
    }

    if (i == TAM || v[i] != x){
        return -1;
    } else {
        return i+1;
    }
}

int main(){
    int vetor[TAM + 1] = {1, 2, 3, 4, 5, 9, 12, 15, 16, 18, 0};
    int user;

    printf("Digite o numero que deseja buscar: ");
    scanf("%d", &user);
    
    int pos = buscaOrd(vetor, user);

    if (pos == -1){
        printf("\nErro: neste vetor nao possui o numero %d", user);
    } else {
        printf("\nO numero %d esta na posicao %d", user, pos);
    }
    
    return 0;
}

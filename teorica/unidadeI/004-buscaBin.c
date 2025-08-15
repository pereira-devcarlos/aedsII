#include <stdio.h>
#define TAM 10

int buscaBin(int v[], int user){
    int inicio=0, fim=TAM, meio;

    while (inicio <= fim){
        meio = (inicio + fim)/2;
        if (v[meio] == user){
            return meio+1;
        }
        else if (v[meio] < user){
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }

    return -1;
}

int main(){
    int vetor[TAM]={1, 2, 3, 4, 5, 9, 12, 15, 16, 18};
    int user;

    printf("\nDigite o numero que deseja buscar: ");
    scanf("%d", &user);

    int pos = buscaBin(vetor, user);

    if (pos == -1){
        printf("\nErro: neste vetor nao possui o numero %d", user);
    } else {
        printf("\nO numero %d esta na posicao %d", user, pos);
    }
    

    return 0;
}

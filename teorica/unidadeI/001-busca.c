#include <stdio.h>

int busca1(int vetor[], int tam, int x){
    int i=0;
    while(i<tam){
        if (vetor[i] == x){
            return i+1;
            break;
        }
        else {
            i++;
        }
    }
    return -1; // Retorna -1 se não encontrar
}

int main(){
    int vetor[10]={1, 2, 3, 4, 5, 9, 12, 15, 16, 18};
    int user;

    printf("\nDigite o numero que deseja buscar: ");
    scanf("%d", &user);

    int pos = busca1(vetor, 10, user);
    if (pos == -1){
        printf("\nErro: neste vetor nao possui o numero %d", user);
    } else {
        printf("\nO numero %d esta na posicao %d", user, pos);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    int valor;
} No;

No pai(No vetor[], int i){
    return vetor[(i-1)/2];
}

No filhoEsq(No vetor[], int i){
    return vetor[(2*i)+1];
}

No filhoDir(No vetor[], int i){
    return vetor[(2*i)+2];
}

int indice(No vetor[], int chave){
    for (int i = 0; i < 6; i++){
        if (vetor[i].chave == chave){
            return i;
        }
    }
}

void trocar(No vetor[], No no1, No no2){
    int indiceNo1, indiceNo2;
    indiceNo1 = indice(vetor, no1.chave);
    indiceNo2 = indice(vetor, no2.chave);

    vetor[indiceNo1] = no2;
    vetor[indiceNo2] = no1;
}

void imprimir(No v[], int fim){
    printf("Impressao dos nos da arvore:\n");
    for(int i = 0; i <= fim; i++){
        printf("No %d: chave=%d, valor=%d\n", i, v[i].chave, v[i].valor);
    }
    printf("\n");
}

void insert(No vetor[], int *fim, No novo){
    (*fim)++;
    vetor[*fim] = novo;
    int i = *fim; 

    while (i != 0){
        if (pai(vetor, i).chave > vetor[i].chave){
            trocar(vetor, pai(vetor, i), vetor[i]);
        } else {
            i--;
        }
    }
}

int main(){
    No v[7];
    int fim=2;

    v[0].chave = 2;
    v[0].valor = 7;

    v[1].chave = 3;
    v[1].valor = 10;

    v[2].chave = 6;
    v[2].valor = 20;
    
    No result = pai(v, 2);
    printf("Pai de %d: %d\n", v[2].chave, result.chave);

    result = pai(v, 1);
    printf("Pai de %d: %d\n", v[1].chave, result.chave);

    result = filhoEsq(v, 0);
    int ind = indice(v, result.chave);
    printf("\nFilho a esquerda de %d: %d, indice=%d\n", v[0].chave, result.chave, ind);

    result = filhoDir(v, 0);
    ind = indice(v, result.chave);
    printf("Filho a direita de %d: %d, indice=%d\n", v[0].chave, result.chave, ind);


    No novo = {1, 25};
    insert(v, &fim, novo);
    printf("\nNo inserido: chave=%d, valor=%d\n", novo.chave, novo.valor);

    novo.chave = 4;
    novo.valor = 15;
    insert(v, &fim, novo);

    novo.chave = 5;
    novo.valor = 30;
    insert(v, &fim, novo);
    
    imprimir(v, fim);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAM 10

int chaveMultiplicacao(int chave){
    float A = (sqrt(5) - 1) / 2; // Constante de Knuth
    float produto = chave * A;
    float parteFracionaria = produto - (int)produto;
    int indice = (int)(TAM * parteFracionaria);
    return indice;
}

void insere(int tabela[], int chave){
    int indice = chaveMultiplicacao(chave);
    printf("Inserindo chave %d na posicao %d\n", chave, indice);
    tabela[indice] = chave;
}

void busca(int *tabela, int chave){
    int indice = chaveMultiplicacao(chave);
    if (tabela[indice] == chave){
        printf("\nChave %d foi encontrada na posica %d", chave, indice);
    } else {
        printf("\nChave %d nao foi encontrada na tabela", chave);
    }
    
}

int main(){
    int tabela[TAM];
    for (int i = 0; i < TAM; i++){
        tabela[i] = -1;
    }
    
    insere(tabela, 5);
    insere(tabela, 8);
    insere(tabela, 22);

    busca(tabela, 5);
    busca(tabela, 11);
    
    return 0;
}

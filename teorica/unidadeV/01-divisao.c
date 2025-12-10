#include <stdio.h>
#include <stdlib.h>
#define TAM 10

// Função de hash usando o método da divisão
int chaveDivisao(int chave){
    return chave % TAM;
}

// Inserção na tabela hash
void insere(int tabela[], int chave){
    int indice = chaveDivisao(chave);

    printf("Inserindo chave %d na posição %d\n", chave, indice);
    tabela[indice] = chave;
}

// Busca na tabela hash
void busca(int tabela[], int chave){
    int indice = chaveDivisao(chave);

    printf("\nBuscando chave %d na posição %d\n", chave, indice);
    if(tabela[indice] == chave){
        printf("Chave %d encontrada na posição %d\n", chave, indice);
    } else {
        printf("Chave %d não encontrada\n", chave);
    }
}

int main(){
    int tabela[TAM];
    // Inicializa a tabela com -1 (indicando vazio)
    for(int i = 0; i < TAM; i++){
        tabela[i] = -1; 
    }

    // Testando inserção e busca utilizando a função da divisão
    insere(tabela, 15);
    insere(tabela, 27);

    busca(tabela, 15);
    busca(tabela, 30);

    return 0;
}

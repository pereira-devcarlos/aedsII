#include <stdio.h>
#include <stdlib.h>
#define TAM 10

// Função de hash usando o método da divisão
int chaveDivisao(int chave){
    return chave % TAM;
}

int main(){
    int tabela[TAM];
    // Inicializa a tabela com -1 (indicando vazio)
    for(int i = 0; i < TAM; i++){
        tabela[i] = -1; 
    }

    return 0;
}

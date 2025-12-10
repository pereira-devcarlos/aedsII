#include <stdio.h>
#include <stdlib.h>

/** Tabela Hash Universal
 *  Tabela hash para CPFs utilizando funcao hash universal
 *  h(k) = ((a*k + b) mod p) mod TAM
*/

// Constantes
#define TAM 10
#define A 31
#define B 7

// Como será para CPFs, usamos um primo grande para p > 10^11
#define P 100000000019


// Função hash universal
int chaveUniversal(long long int chave){
    return ((A * chave + B) % P) % TAM;
}

void insere(long long int tabela[], long long int chave){
    int indice = chaveUniversal(chave);

    printf("Inserindo chave %lld na posicao %d\n", chave, indice);
    tabela[indice] = chave;
}

void busca(long long int tabela[], long long int chave){
    int indice = chaveUniversal(chave);

    if(tabela[indice] == chave){
        printf("Chave %lld encontrada na posicao %d\n", chave, indice);
    } else {
        printf("Chave %lld nao encontrada\n", chave);
    }
}

int main(){
    // Tipo long long int para suportar CPFs
    long long int tabela[TAM] = {-1}; // Inicializa tabela com -1 (indicando vazio)

    // Exemplo de inserção de CPFs na tabela hash
    insere(tabela, 123456789012LL);
    insere(tabela, 987654321098LL);
    insere(tabela, 11122233344LL);

    // Exemplo de busca de CPFs na tabela hash
    busca(tabela, 123456789012LL);
    busca(tabela, 55566677788LL);

    return 0;
}

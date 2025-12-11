#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAM 10
int contador = 0;

enum{Vazio, Ocupado, Removido};

typedef struct {
    int chave;
    int status;
} Hash;

// Função de hash primária
int h1(int chave){
    float A = (sqrt(5) - 1) / 2; // Constante de Knuth
    float produto = chave * A;
    float parteFracionaria = produto - (int)produto;
    int indice = (int)(TAM * parteFracionaria);
    return indice;
}

// Função de hash secundária (deve ser diferente de zero)
int h2(int chave){
    return 1 + (chave % (TAM - 1));
}

void insere(Hash tabela[], int chave){
    if (contador == TAM){
        printf("\nErro: tabela cheia!!");
        return;
    }
    int indice = h1(chave);
    int passo = h2(chave);

    for (int i = 0; i < TAM; i++){
        int modIndice = (indice + i * passo) % TAM;
        if (tabela[modIndice].status != Ocupado){
            tabela[modIndice].chave = chave;
            tabela[modIndice].status = Ocupado;
            printf("Inserindo chave %d na posição %d\n", chave, modIndice);
            contador++;
            return;
        }
    }
}

void busca(Hash tabela[], int chave){
    int indice = h1(chave);
    int passo = h2(chave);
    printf("\nBuscando chave %d\n", chave);

    for (int i = 0; i < TAM; i++){
        int modIndice = (indice + i * passo) % TAM;
        if (tabela[modIndice].status == Vazio){
            break;
        }
        if (tabela[modIndice].status == Ocupado &&
            tabela[modIndice].chave == chave){
            printf("Chave %d encontrada na posição %d\n", chave, modIndice);
            return;
        }
    }
    printf("Chave %d não encontrada\n", chave); 
}

void remover(Hash tabela[], int chave){
    int indice = h1(chave);
    int passo = h2(chave);

    for (int i = 0; i < TAM; i++){
        int modIndice = (indice + i * passo) % TAM;
        if (tabela[modIndice].status == Vazio){
            break;
        }
        if (tabela[modIndice].status == Ocupado &&
            tabela[modIndice].chave == chave){
            tabela[modIndice].status = Removido;
            contador--;
            printf("\nChave %d na posicao %d foi removida\n", chave, modIndice);
            return;
        }
    }
    printf("\nErro: chave %d inexistente\n", chave);
}

int main(){
    Hash tabela[TAM];
    for(int i = 0; i < TAM; i++){
        tabela[i].status = Vazio; 
    }

    insere(tabela, 15);
    insere(tabela, 25);
    insere(tabela, 5);

    busca(tabela, 25);
    busca(tabela, 5);

    remover(tabela, 25);
    busca(tabela, 25);

    return 0;
}
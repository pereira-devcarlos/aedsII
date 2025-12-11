#include <stdio.h>
#include <stdlib.h>
#define TAM 10
int contador = 0;

// Status da célula na tabela hash
enum{Vazio, Ocupado, Removido};

// Estrutura da célula da tabela hash
typedef struct {
    int chave;
    int status;
} Hash;

// Função de hash usando o método da divisão
int chaveDivisao(int chave){
    return chave % TAM;
}

// Inserção na tabela hash
void insere(Hash tabela[], int chave){
    if (contador == TAM){
        printf("\nErro: tabela cheia!!");
        return;
    }
    
    int indice = chaveDivisao(chave);
    
    for (int i = 0; i < TAM; i++){
        int modIndice = (indice + i) % TAM;
        if (tabela[modIndice].status != Ocupado){
            // Inserindo a chave e atualizando o status
            tabela[modIndice].chave = chave;
            tabela[modIndice].status = Ocupado;
            printf("Inserindo chave %d na posição %d\n", chave, modIndice);
            contador++;
            return;
        } 
    }
    
}

// Busca na tabela hash
void busca(Hash tabela[], int chave){
    int indice = chaveDivisao(chave);
    
    if (tabela[indice].status != Vazio){
        for (int i = 0; i <= contador; i++){
            int modIndice = (indice + i) % TAM;
            printf("\nBuscando chave %d na posição %d: ", chave, modIndice);
            if(tabela[modIndice].status == Ocupado &&
                tabela[modIndice].chave == chave){
                printf("foi encontrada!\n", chave, modIndice);
                return;
            } else {
                printf("nao foi encontrada", chave); 
            }
        }
    }
    printf("\nChave %d inexistente", chave);
}

void remover(Hash tabela[], int chave){
    int indice = chaveDivisao(chave);
    if (tabela[indice].status != Vazio) {
        int modIndice = (indice + 1) % TAM;
        for (int i = 0; i <= contador; i++){
            if (tabela[modIndice].status == Ocupado && tabela[modIndice].chave == chave){
                tabela[modIndice].status = Removido;
                contador--;
                printf("\nChave %d na posicao %d foi removida", chave, modIndice);
                return;
            }
        }
    }
    printf("\nErro: chave %d inexistente", chave);
}

int main(){
    Hash tabela[TAM];
    // Inicializa a tabela com -1 (indicando vazio)
    for(int i = 0; i < TAM; i++){
        tabela[i].status = Vazio; 
    }

    // Testando inserção e busca utilizando a função da divisão
    insere(tabela, 15);
    insere(tabela, 25);
    insere(tabela, 5);

    busca(tabela, 25);
    busca(tabela, 5);

    remover(tabela, 25);
    busca(tabela, 25);

    return 0;
}

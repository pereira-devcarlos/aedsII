#include <stdio.h>
#include <stdlib.h>
#define M 3 // Tamanho máximo da fila
// Váriaveis Globais
int in = -1; // Inicio da fila
int re = -1; // Retaguarda

typedef struct {
    int chave;
    int valor;
} No;

// Função de inserir um nó na fila
int insert(No f[], int *in, int *re, No ins){
    // Inicializa já com o retorno -1 caso a fila tiver cheia
    int pos = -1; 

    int prov = ((*re) + 1) % M;

    if (prov != *in){
        *re = prov;
        f[*re] = ins;
        pos = *re;

        // Se a fila estiver vazia o inicio avança também
        if (*in == -1){
            *in = 0;
        }
    }

    return pos;
}

// Função para remover um nó da fila 
No *remover(No F[], int *in, int *re){
    // Verificando se a Fila está vazia
    if (*in != -1){
        // Armazenando a posição do inicio
        int pos = *in;  
        if (*in != *re){
            int prov = ((*in)+1) % M;
            *in = prov;
        } else {
            // Se inicio for igual a retaguarda 
            // a fila fica vazia
            *in = -1;
            *re = -1;
        }
        // Retorna o nó que foi removido
        return &F[pos];
    }
    // Retorna Nulo caso a fila tiver vazia
    return NULL;
}

// Função para exibir o resultado do insert
void resultInsert(No F[], int result){
    if (result == -1) {
        printf("Fila cheia! Nao foi possivel inserir o no.\n");
    } else {
        printf("Elemento inserido na fila posicao %d -> chave: %d, valor: %d\n", result, F[re].chave, F[re].valor);
    }
}

// Função para exibir o resultado do remover
void resultRemove(No* rem){
    if (rem == NULL) {
        printf("Fila vazia!\n");
    } else {
        printf("Removido: chave %d, valor %d\n", rem->chave, rem->valor);
    }
}

int main(){
    No F[M]; // Nó da fila
    No ins;  // Nó para dados de inserção
    No* rem; // Ponteiro de nó para a remoção
    int result; // Armazenar resultados das funções
   
    // Testando inserção
    ins.chave = 1; ins.valor= 7;
    result = insert(F, &in, &re, ins);
    resultInsert(F, result);

    // Testando Remoção
    rem = remover(F, &in, &re);
    resultRemove(rem);    

    return 0;
}
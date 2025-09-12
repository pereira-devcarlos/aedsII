#include <stdio.h>
#include <stdlib.h>
#define M 3 // Tamanho máximo da fila
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

// Função para exibir o resultado do insert
void exibirInsert(No F[], int result){
    if (result == -1) {
        printf("Fila cheia! Nao foi possivel inserir o no.\n");
    } else {
        printf("Elemento inserido na fila posicao %d -> chave: %d, valor: %d\n", result, F[re].chave, F[re].valor);
    } 
}

int main(){
    No F[M]; // Nó da fila
    No ins;  // Nó para dados de inserção
    int result; // Armazenar resultados das funções

    // Testando inserções
    ins.chave = 1; ins.valor= 7;
    result = insert(F, &in, &re, ins);
    exibirInsert(F, result);

    ins.chave = 2; ins.valor= 13;
    result = insert(F, &in, &re, ins);
    exibirInsert(F, result);

    ins.chave = 3; ins.valor= 20;
    result = insert(F, &in, &re, ins);
    exibirInsert(F, result);

    ins.chave = 4; ins.valor= 17;
    result = insert(F, &in, &re, ins);
    exibirInsert(F, result);

    return 0;
}

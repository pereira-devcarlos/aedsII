#include <stdio.h>
#include <stdlib.h>
#define M 3 // Tamanho máximo da fila
int in = -1; // Inicio da fila
int re = -1; // Retaguarda

typedef struct {
    int chave;
    int valor;
} No;

int insert(No f[], int *in, int *re, No ins){
    // Inicializa já com o retorno -1 caso a fila tiver cheia
    int pos = -1; 

    if (*in == -1) {  // Fila vazia
        *in = 0;      // Inicio vai para a primeira posição da Fila
        *re = 0;      // Retaguarda também para a primeira pos da Fila
        f[*re] = ins; // Fila recebe o nó a ser inserido
        pos = *re;    // Retorna a posição da retaguarda
    } else {
        int prov = ((*re) + 1) % M;
        if (prov != *in) { // Fila não está cheia
            *re = prov;    // Atualiza a retaguarda
            f[*re] = ins;  // Fila recebe o nó a ser inserido
            pos = *re;     // Retorna a posição da retaguarda
        }
    }

    return pos;
}

int main(){
    No F[M]; // Nó da fila
    
    No ins = {4, 20};
    int res = insert(F, &in, &re, ins);

    if (res == -1) {
        printf("Fila cheia! Nao foi possivel inserir o no.\n");
    } else {
        printf("Elemento inserido na fila posicao %d -> chave: %d, valor: %d\n", res, F[re].chave, F[re].valor);
    } 

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int chave;
    int valor;
} No;

int insert(No p[], int *topo, No ins){
    if (*topo < 9){
        (*topo)++;
        p[*topo]= ins;
        return *topo;
    }
    return -1;
}

int main(){
    No P[10]={
        {1, 30},
        {2, 20},
        {3, 15}
    };
    int topo = 2;

    No ins = {4, 20};
    int res = insert(P, &topo, ins);

    if (res == -1) {
        printf("Pilha cheia! Não foi possível inserir.\n");
    } else {
        printf("Elemento inserido no topo %d -> chave: %d, valor: %d\n",res, P[topo].chave, P[topo].valor);
    }

    return 0;
}

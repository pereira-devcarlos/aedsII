#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int chave;
    int valor;
} No;

/** Função de inserir um novo nó na pilha 
 * p[] = Nó que ira receber o a inserção
 * topo = O topo que toda pilha precisa para inserir e remover nó
 * ins = Nó que ira ser inserido na pilha
 * 
 * Retorno:
 * Caso for inserido com sucesso retorna o valor do topo
 * Caso a pilha esteja cheia irá retornar -1
*/
int insert(No p[], int *topo, No ins){
    // Verifica se a pilha tem espaço disponivel
    if (*topo < 9){
        (*topo)++;
        p[*topo]= ins;
        return *topo;
    }
    // Pilha cheia retorna -1
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

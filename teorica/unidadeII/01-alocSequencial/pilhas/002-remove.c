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

/** Função de remoção de um nó da pilha
 * p[] = Nó que irá acontecer a remoção
 * topo = O topo que toda pilha precisa para inserir e remover nó
 * 
 * Retorno:
 * Irá retornar o nó removido (caso possui um nó a ser removido)
 * Irá retornar um nó nulo caso não possuir um nó a ser removido
 */
No remover(No P[], int *topo){
    // Verifica se possui um nó na pilha
    if (*topo >= 0){
        No removido = P[*topo];
        (*topo)--;
        return removido;
    }
    // Caso não possuir um nó irá retornar um nó vazio
    No vazio = {0, 0};
    return vazio;
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

    No rem = remover(P, &topo);
    printf("Elemento removido: chave %d, valor %d\n\n", rem.chave, rem.valor); 

    return 0;
}

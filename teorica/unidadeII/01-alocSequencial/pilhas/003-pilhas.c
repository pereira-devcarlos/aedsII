#include <stdio.h>
#include <stdlib.h>

typedef struct { 
    int chave;
    int valor;
} No;

int busca(No p[], int topo, int x){
    for (int i = 0; i <= topo; i++){
        if (p[i].chave == x){
            return i;
        }
    }
    return -1;
}

/** Função de inserir um novo nó na pilha 
 * p[] = Nó que ira receber o a inserção
 * topo = O topo que toda pilha precisa para inserir e remover nó
 * ins = Nó que ira ser inserido na pilha
 * 
 * Retorno:
 * Caso for inserido com sucesso retorna o valor do topo
 * Caso a pilha esteja cheia irá retornar -2
*/
int insert(No p[], int *topo, No ins){
    // Verifica se a pilha tem espaço disponivel
    if (*topo < 9){
        if (busca(p, *topo, ins.chave) == -1){
            (*topo)++;
            p[*topo]= ins;
            return *topo;
        }
        // Chave já existente retorna -1
        return -1;
    }
    // Pilha cheia retorna -2
    return -2;
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
    No vazio = {-1, 0};
    return vazio;
}

int main(){
    No P[10]; // Pilha com 10 posições
    // Topo inicializado com -1 (Já que não possui nada na pilha)
    int topo = -1; 
    
    int opcao = 1;
    while (opcao != 0){
        printf("\n===== Menu de Opcoes =====\n");
        printf("[1]-Inserir um no\n");
        printf("[2]-Remover um no\n");
        printf("[3]-Listar a pilha\n");
        printf("[0]-Encerrar o programa\n");
        printf("Insira a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:{
            No ins; // Nó para inserção
            // Entrada de dados para o nó ins
            printf("\nDigite a chave do seu no: ");
            scanf("%d", &ins.chave);

            printf("Digite o valor do seu no: ");
            scanf("%d", &ins.valor);

            // Guardando o retorno da função insert em result
            int result = insert(P, &topo, ins);

            // Condicionais para a impressão do resultado da inserção
            if (result == -2) {
                printf("\nPilha cheia! Nao foi possível inserir um no.\n");
            } else if (result == -1) {
                printf("\nChave existente! Nao foi possivel inserir um no.\n");
            } else {
                printf("\nElemento inserido no topo %d -> chave: %d, valor: %d\n",result, P[topo].chave, P[topo].valor);
            }
            break;
            }
        case 2: {
            // Nó a ser removido
            No rem = remover(P, &topo);

            // Condicionais para imprimir o resultado da remoção da pilha
            if (rem.chave != -1){
                printf("\nElemento removido: chave %d, valor %d\n", rem.chave, rem.valor); 
            } else {
                printf("\nErro: nao possui no a ser removido da pilha\n"); 
            }
            break;
            }
        case 3:{
            // Imprimir todos os nós existente na pilha
            if (topo>=0){
                printf("\nListar pilha:\n");
                for (int i = 0; i <= topo; i++){
                    printf("Elemento %d: chave %d, valor %d\n", i+1, P[i].chave, P[i].valor);
                }
            } else {
                printf("\nErro: nao possui nenhum elemento nesta pilha!!!\n");
            }
            break;
        }
        case 0:{
            printf("\nEncerrando programa...\n\n");
            break;
            }    
        default:
            printf("\nErro: opcao invalida!\n");
            break;
        }
    
    }

    return 0;
}

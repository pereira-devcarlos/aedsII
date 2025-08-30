#include <stdio.h>
#include <stdlib.h>

typedef struct { 
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
            if (result == -1) {
                printf("\nPilha cheia! Não foi possível inserir.\n");
            } else {
                printf("\nElemento inserido no topo %d -> chave: %d, valor: %d\n",result, P[topo].chave, P[topo].valor);
            }
            break;
            }
        case 2: {
            No rem = remover(P, &topo);
            printf("Elemento removido: chave %d, valor %d\n\n", rem.chave, rem.valor); 
        
            break;
            }
        case 0:{
            printf("\nEncerrando programa...\n\n");

            break;
            }    
        default:
            break;
        }
    
    }
    

    return 0;
}

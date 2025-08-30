#include <stdio.h>
#include <stdlib.h>
#define M 3 // Tamanho máximo da fila

// Váriaveis Globais
int in = -1; // Inicio da fila
int re = -1; // Retaguarda da fila

typedef struct {
    int chave;
    int valor;
} No;

int insert(No f[], int *in, int *re, No ins); // Função de inserir um nó na fila
No *remover(No F[], int *in, int *re);        // Função para remover um nó da fila 
void listarFila(No F[], int in, int re);      // Função para listar os nós da fila
void resultInsert(No F[], int result); // Função para exibir o resultado do insert
void resultRemove(No* rem);            // Função para exibir o resultado do remove
void exibirMenu();

int main(){
    No F[M]; // Nó da fila
    No ins;  // Nó para dados de inserção
    No* rem; // Ponteiro de nó para a remoção
    int result; // Armazenar o resultado da função de inserção

    int opcao = 1;
    while (opcao != 0){
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao){
        case 1:{
            // Entrada de dados ao nó que será inserido na fila
            printf("\nDigite a chave do seu no: ");
            scanf("%d", &ins.chave);
            printf("Digite o valor do seu no: ");
            scanf("%d", &ins.valor);

            
            // Chamando a função de inserção e imprimindo o resultado
            result = insert(F, &in, &re, ins);
            resultInsert(F, result); 

            break;
        }
        case 2:{
            // Chamando a função de remoção e imprimindo o resultado
            rem = remover(F, &in, &re);
            resultRemove(rem);

            break;
        }
        case 3:{
            // Chamando a função que lista todos os elementos da fila
            listarFila(F, in, re);

            break;
        }
        case 0:{
            printf("\nEncerrando o programa...\n");
            break;
        }
        default:{
            printf("\nErro: opcao invalida!!!\n");
            break;
        }
        }
    }

    return 0;
}

// Função de inserir um nó na fila
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

// Função para listar a fila inteira
void listarFila(No F[], int in, int re){
    int prov = in; // Variável provisória
    // Verificando se a fila está vazia
    if (in == -1){
        printf("\nFila vazia!\n");
    } else {
        printf("\nListar Fila:");
        // Loop para exibir todos os elementos da fila
        while (in != -1){
            if (in != re){
                prov = (in+1) % M;
                printf("\nElemento da fila na posicao %d -> chave: %d, valor: %d;", in, F[in].chave, F[in].valor);
                in = prov;
            } else { // Inicio == a Retaguarda é a ultima posição da fila
                printf("\nElemento da fila na posicao %d -> chave: %d, valor: %d;\n", in, F[in].chave, F[in].valor);
                in = -1; // Atribuindo -1 ao inicio para sair do loop
            }
        }
    }
}

// Função para exibir o resultado do insert
void resultInsert(No F[], int result){
    if (result == -1) {
        printf("\nFila cheia! Nao foi possivel inserir o no.\n");
    } else {
        printf("\nElemento inserido na fila posicao %d -> chave: %d, valor: %d\n", result, F[re].chave, F[re].valor);
    }
}

// Função para exibir o resultado do remover
void resultRemove(No* rem){
    if (rem == NULL) {
        printf("\nFila vazia!\n");
    } else {
        printf("\nRemovido: chave %d, valor %d\n", rem->chave, rem->valor);
    }
}

void exibirMenu(){
    printf("\n===== Menu de Opcoes =====\n");
    printf("[1]-Inserir um no na fila\n");
    printf("[2]-Remover um no da fila\n");
    printf("[3]-Listar todos elementos\n");
    printf("[0]-Encerrar o programa!!\n");
    printf("Digite a opcao que deseja realizar: ");
}

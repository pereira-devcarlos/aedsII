#include <stdio.h>
#include <stdlib.h>
#define MAX 7 // Tamanho maximo da arvore heap

// Definicao da estrutura do no da arvore heap
typedef struct no {
    int chave;
    int valor;
} No;

// Retorna o no pai do no na posicao i
No pai(No vetor[], int i){
    return vetor[(i-1)/2];
}

// Retorna o no filho esquerdo do no na posicao i
No filhoEsq(No vetor[], int i){
    return vetor[(2*i)+1];
}

// Retorna o no filho direito do no na posicao i
No filhoDir(No vetor[], int i){
    return vetor[(2*i)+2];
}

// Retorna o indice do no com a chave especificada
int indice(No vetor[], int chave){
    for (int i = 0; i < 6; i++){
        if (vetor[i].chave == chave){
            return i;
        }
    }
}

// Troca os dois nos especificados no vetor
void trocar(No vetor[], No no1, No no2){
    int indiceNo1, indiceNo2;
    indiceNo1 = indice(vetor, no1.chave);
    indiceNo2 = indice(vetor, no2.chave);

    vetor[indiceNo1] = no2;
    vetor[indiceNo2] = no1;
}

// Retorna -1 se a chave nao for encontrada, senao retorna a chave
int busca(No vetor[], int fim, int chave){
    for (int i = 0; i <= fim; i++){
        if (vetor[i].chave == chave){
            return chave;
        }
    }
    return -1;
}

// Imprime os nos do arvore
void imprimir(No v[], int fim){
    printf("Impressao dos nos da arvore:\n");
    for(int i = 0; i <= fim; i++){
        printf("No posicao %d: chave=%d, valor=%d\n", i, v[i].chave, v[i].valor);
    }
    printf("\n");
}

// Insere um novo no na arvore heap
void insert(No vetor[], int *fim, No novo){
    // Verifica se a arvore esta cheia
    if ((*fim)+1 == MAX){
        printf("\nErro: arvore cheia!\n");
        return;
    }

    // Verifica se ja existe um no com a mesma chave
    if (busca(vetor, *fim, novo.chave) != -1){
        printf("\nErro: ja possui no com esta chave!\n");
        return;
    }
    
    // Insere o novo no na ultima posicao 
    (*fim)++;
    vetor[*fim] = novo;
    int i = *fim; 

    // Reorganiza a arvore para manter a propriedade de heap
    while (i != 0 && pai(vetor, i).chave > vetor[i].chave){
        trocar(vetor, pai(vetor, i), vetor[i]);
        i = indice(vetor, novo.chave);
    }
}

int main(){
    No v[MAX];
    int fim=2;

    // Inicializacao dos nos da arvore
    v[0].chave = 2;
    v[0].valor = 7;

    v[1].chave = 3;
    v[1].valor = 10;

    v[2].chave = 6;
    v[2].valor = 20;
    
    // Testes das funcoes pai, filhoEsq, filhoDir e indice
    No result = pai(v, 2);
    printf("Pai de %d: %d\n", v[2].chave, result.chave);

    result = pai(v, 1);
    printf("Pai de %d: %d\n", v[1].chave, result.chave);

    result = filhoEsq(v, 0);
    int ind = indice(v, result.chave);
    printf("\nFilho a esquerda de %d: %d, indice=%d\n", v[0].chave, result.chave, ind);

    result = filhoDir(v, 0);
    ind = indice(v, result.chave);
    printf("Filho a direita de %d: %d, indice=%d\n", v[0].chave, result.chave, ind);


    // Teste da funcao insert
    No novo = {1, 25};
    insert(v, &fim, novo);
    printf("\nNo inserido: chave=%d, valor=%d\n\n", novo.chave, novo.valor);

    novo.chave = 4;
    novo.valor = 15;
    insert(v, &fim, novo);

    novo.chave = 5;
    novo.valor = 30;
    insert(v, &fim, novo);
    
    novo.chave = 8;
    novo.valor = 30;
    insert(v, &fim, novo);

    // Impressao dos nos da arvore apos insercoes
    imprimir(v, fim);

    return 0;
}

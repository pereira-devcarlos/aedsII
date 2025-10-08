#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore
typedef struct no {
    int valor, altura;
    struct no *dir, *esq;
} No;

// Função para criar um novo nó
No* criarNo(int valor){
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->altura = 1;  // Altura inicial do nó é 1
    novo->dir=NULL;
    novo->esq=NULL;
    return novo;
}

// Função para retornar a altura de uma árvore
int altura(No* raiz){
    if (raiz == NULL) return 0;
    
    int esq = altura(raiz->esq);
    int dir = altura(raiz->dir);
    if (esq > dir){
        return esq + 1;
    } else {
        return dir + 1;
    }
}

// Função para retornar o valor do FB
int fatorBalanceamento(No* raiz){
    if(raiz != NULL){
        return altura(raiz->esq) - altura(raiz->dir);
    }
    // Se não possuir a raiz
    return 0;
}

// Função de rotação para esquerda
No* rotacionaEsq(No* raiz){
    No* nova = raiz->dir;
    raiz->dir = nova->esq;
    nova->esq = raiz;
    return nova;
}

// Função de rotação para direita
No* rotacionaDir(No* raiz){
    No* nova = raiz->esq;
    raiz->esq = nova->dir;
    nova->dir = raiz;
    return nova;
}

// Função de rotação dupla para esquerda e direita
No* rotacionaEsqDir(No* raiz){
    raiz->esq = rotacionaEsq(raiz->esq);
    raiz = rotacionaDir(raiz);
    return raiz;
}

// Função de rotação dupla para direita e esquerda
No* rotacionaDirEsq(No* raiz){
    raiz->dir = rotacionaDir(raiz->dir);
    raiz = rotacionaEsq(raiz);
    return raiz;
}

// Função para inserir um valor na árvore binária de busca
No* insertArvore(No* raiz, int valor){
    if (raiz == NULL){
        raiz = criarNo(valor);
    } else {
        if (valor < raiz->valor){
            raiz->esq = insertArvore(raiz->esq, valor);
        } else {
            raiz->dir = insertArvore(raiz->dir, valor);
        }
    }
    
    return raiz;
}

// Funções de exibição da árvore 
void exibirPreOrdem(No* raiz){
    if (raiz == NULL) return;
    printf("%d ", raiz->valor);
    exibirPreOrdem(raiz->esq);
    exibirPreOrdem(raiz->dir);
}
void exibirEmOrdem(No* raiz){
    if (raiz == NULL) return;
    exibirEmOrdem(raiz->esq);
    printf("%d ", raiz->valor);
    exibirEmOrdem(raiz->dir);
}
void exibirPosOrdem(No* raiz){
    if (raiz == NULL) return;
    exibirPosOrdem(raiz->esq);
    exibirPosOrdem(raiz->dir);
    printf("%d ", raiz->valor);
}

int main(){
    No* raiz=NULL;
    
    raiz = insertArvore(raiz, 20);
    insertArvore(raiz, 10);
    insertArvore(raiz, 5);
    insertArvore(raiz, 30);
    insertArvore(raiz, 50);
    insertArvore(raiz, 25);
    insertArvore(raiz, 70);
    
    printf("Exibindo a arvore em pre ordem:\n");
    exibirPreOrdem(raiz);

    int alturaArvore = altura(raiz);
    printf("\nAltura dessa arvore: %d", alturaArvore);

    int fator = fatorBalanceamento(raiz);
    printf("\nFator de balanceamento: %d", fator);

    return 0;
}

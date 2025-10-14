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

// Função para retornar a altura de um nó
int altura(No* raiz){
    if (raiz == NULL) return 0;
    return raiz->altura;
}

// Função para atualizar a altura de um nó
void atualizarAltura(No* raiz) {
    if (raiz) {
        int esq = altura(raiz->esq);
        int dir = altura(raiz->dir);
        if (esq > dir){
            raiz->altura = esq + 1;
        } else {
            raiz->altura = dir + 1;
        }
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

    // Atualiza as alturas dos nós
    atualizarAltura(raiz);
    atualizarAltura(nova);

    return nova;
}

// Função de rotação para direita
No* rotacionaDir(No* raiz){
    No* nova = raiz->esq;
    raiz->esq = nova->dir;
    nova->dir = raiz;

    // Atualiza as alturas dos nós
    atualizarAltura(raiz);
    atualizarAltura(nova);
    
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

// Função para balancear a árvore
No* balancear(No* raiz){
    // Armazena o fator de balanceamento
    int fator = fatorBalanceamento(raiz);

    // Verifica e aplica as rotações necessárias
    if (fator < -1 && fatorBalanceamento(raiz->dir) <= 0){
        raiz = rotacionaEsq(raiz);
    } else if (fator > 1 && fatorBalanceamento(raiz->esq) >= 0){
        raiz = rotacionaDir(raiz);
    } else if (fator > 1 && fatorBalanceamento(raiz->esq) < 0){
        raiz = rotacionaEsqDir(raiz);
    } else if (fator < -1 && fatorBalanceamento(raiz->dir) > 0){
        raiz = rotacionaDirEsq(raiz);
    }
    // Retorna a raiz possivelmente modificada
    return raiz;
}

// Função para inserir um valor na árvore binária de busca
No* insertArvore(No* raiz, int valor){
    // Se a árvore estiver vazia, cria um novo nó
    if (raiz == NULL){
        raiz = criarNo(valor);
    } else {
        // Caso contrário, insere recursivamente na esquerda ou direita
        if (valor < raiz->valor){
            raiz->esq = insertArvore(raiz->esq, valor);
        } else {
            raiz->dir = insertArvore(raiz->dir, valor);
        }
    }

    // Sempre atualizar a altura após a inserção
    atualizarAltura(raiz);
    
    // Verifica e se caso necessário, irá balancear a árvore
    raiz = balancear(raiz);

    return raiz;
}

// Função para buscar um nó da árvore
No* buscaNo(No* raiz, int valor){
    if (raiz == NULL) return raiz;
    
    if (valor < raiz->valor){
        buscaNo(raiz->esq, valor);
    } else {
        buscaNo(raiz->dir, valor);
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
    raiz = insertArvore(raiz, 10);
    raiz = insertArvore(raiz, 5);
    raiz = insertArvore(raiz, 30);
    raiz = insertArvore(raiz, 50);
    raiz = insertArvore(raiz, 25);
    raiz = insertArvore(raiz, 70);
    
    printf("Exibindo a arvore em pre ordem:\n");
    exibirPreOrdem(raiz);

    return 0;
}

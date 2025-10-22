#include<stdio.h> 
#include<stdlib.h> 
#include "avl.h"
  
struct Node *removeNode(struct Node *raiz, int x);

// Obtem a altura da AVL
int altura(struct Node *N) { 
    if (N == NULL) {
        return 0; 
    }
    return N->altura; 
} 
  
// Obtem o máximo entre dois inteiros
int max(int a, int b)  { 
    if (a < b) {
        return (b);
    } 
    return (a); 
} 
  
/* Cria um novo nó com apontadores esquerda e direita nulos */
struct Node* newNode(int valor) { 
    struct Node* node = (struct Node*) malloc(sizeof(struct Node)); 
    node->valor     = valor; 
    node->esquerda  = NULL; 
    node->direita   = NULL; 
    node->altura    = 1;  // Novo nó é adicionado como folha
    return(node); 
} 
  
// Faz a rotação a direita na raiz y
struct Node *direitaRotate(struct Node *y) { 
    struct Node *x = y->esquerda; 
    struct Node *T2 = x->direita; 
  
    // Realiza a rotação
    x->direita = y; 
    y->esquerda = T2; 
  
    // Atualiza as alturas
    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1; 
    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1; 
  
    // Retorna a nova raiz
    return x; 
} 

// Faz a rotação a esquerda na raiz x
struct Node *esquerdaRotate(struct Node *x) { 
    struct Node *y = x->direita; 
    struct Node *T2 = y->esquerda; 
    
    // Realiza a rotação
    y->esquerda = x;
    x->direita = T2;

    // Atualiza as alturas
    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;
    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;
  
    // Retorna a nova raiz
    return y; 
} 
  
// Obtem o fator de balanceamento para o nó N
int balanceamento(struct Node *N) { 
    if (N == NULL) {
        return 0; 
    }
    return (altura(N->esquerda) - altura(N->direita)); 
} 

// Função para balancear a árvore
struct Node *balancear(struct Node *node){
    // Obtem o fator de balanceamento da raiz
    int balance = balanceamento(node);

    // Verifica os quatro casos possíveis de desbalanceamento
    // Caso Esquerda Esquerda
    if (balance > 1 && balanceamento(node->esquerda) >= 0) {
        return direitaRotate(node); 
    }
    // Caso Direita Direita
    if (balance < -1 && balanceamento(node->direita) <= 0) {
        return esquerdaRotate(node); 
    }
    // Caso Esquerda Direita
    if (balance > 1 && balanceamento(node->esquerda) <= 0) { 
        node->esquerda =  esquerdaRotate(node->esquerda); 
        return direitaRotate(node); 
    } 
    // Caso Direita Esquerda
    if (balance < -1 && balanceamento(node->direita) >= 0) { 
        node->direita = direitaRotate(node->direita); 
        return esquerdaRotate(node); 
    } 
    // Retorna o ponteiro (não-atualizado) para a raiz
    // já que não houve desbalanceamento
    return node;
}

// Função recursiva para inserir um novo item na árvore com raiz
// *Node e retorna a nova raiz da subárvore
struct Node* inserir(struct Node* node, int valor) { 
    /* 1.  Realiza a inserção normal de árvore binária */
    if (node == NULL) {
        return(newNode(valor)); 
    }
  
    if (valor < node->valor) {
        node->esquerda  = inserir(node->esquerda, valor); 
    } else if (valor > node->valor){ 
        node->direita = inserir(node->direita, valor); 
    } else { 
        // Valores duplicados não são permitidos na AVL
        return node; 
    }

    /* 2. Atualiza a altura de seu antecessor */
    node->altura = 1 + max(altura(node->esquerda), altura(node->direita)); 
  
    /* 3. Se precisar após a inserção irá balancear a árvore*/
    node = balancear(node);
    
    return node; 
} 

// Função para remover a raiz
struct Node *removeRaiz(struct Node *raiz){
    // Caso de apenas 1 filho a direita ou nenhum
    if (raiz->esquerda == NULL){
        // Verifica se há filho a direita
        if (raiz->direita != NULL){
            raiz = raiz->direita;
            return raiz;
        }
        // Não há filhos(é folha)
        return NULL;
    }
    
    // Caso houver filho a esquerda
    struct Node *q = raiz->esquerda;

    // Procura o maior valor na subárvore esquerda
    while (q->direita != NULL){
        q = q->direita;
    }
    // Substitui o valor da raiz pelo maior valor da subárvore esquerda
    raiz->valor = q->valor;

    // Remove o nó que continha o maior valor da subárvore esquerda
    raiz->esquerda = removeNode(raiz->esquerda, q->valor);
    return raiz;
}

// Função de remover um nó
struct Node *removeNode(struct Node *raiz, int x){
    // Caso base: árvore vazia
    if (raiz == NULL) return NULL;

    // Procura o nó a ser removido
    if (raiz->valor > x){
        raiz->esquerda = removeNode(raiz->esquerda, x);
    } else if (raiz->valor < x){
        raiz->direita = removeNode(raiz->direita, x);
    } else {
        // Nó encontrado irá ser removido
        raiz = removeRaiz(raiz);
        // Se após remoção a raiz for nula, retorna nulo
        if(raiz == NULL) return NULL;
    }    

    // Atualiza a altura da raiz e balanceia a árvore
    raiz->altura = 1 + max(altura(raiz->esquerda), altura(raiz->direita));
    raiz = balancear(raiz);
    return raiz;
} 
  
// Imprime os nós em ordem
void inOrder(struct Node *raiz) { 
    if(raiz != NULL) { 
        inOrder(raiz->esquerda); 
        printf("%d ", raiz->valor); 
        inOrder(raiz->direita); 
    } 
} 

// Imprime os nós em pré ordem
void preOrder(struct Node *raiz){
    if (raiz != NULL){
        printf("%d ", raiz->valor);
        preOrder(raiz->esquerda);
        preOrder(raiz->direita);
    }
}
  
/* Driver program to test above function*/
int main() { 
    struct Node *raiz = NULL; 
  
    /* Constructing tree given in the above figure */
    raiz = inserir(raiz, 10); 
    raiz = inserir(raiz, 20); 
    raiz = inserir(raiz, 30); 
    raiz = inserir(raiz, 40); 
    raiz = inserir(raiz, 50); 
    raiz = inserir(raiz, 25); 
    raiz = inserir(raiz, 5); 
    
    /* A árvore AVL construída será
              30 
             /  \ 
            20   40 
           /  \    \ 
         10  25    50 
        /
       5

    A saida correta em pre-ordem é 30 20 10 5 25 40 50 */
    
    printf("Os elementos da arvore, em ordem, sao:\n"); 
    inOrder(raiz); 
    printf("\n");

    printf("\nOs elementos da arvore, em pre ordem, sao:\n"); 
    preOrder(raiz); 
    printf("\n");

    raiz = removeNode(raiz, 40);

        /* A árvore AVL após a remoção do 40 será
            30                30               20
           /  \              /  \             /  \
          20  40    ==>    20   50   ==>    10   30
         /  \   \         /  \             /    /  \
        10  25  50      10  25            5   25   50
       /               /
      5               5

    A saida correta em pre-ordem é 20 10 5 30 25 50 */

    printf("\nOs elementos da arvore, em pre ordem, sao:\n"); 
    preOrder(raiz); 
    printf("\n");

    return 0; 
} 
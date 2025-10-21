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

struct Node *balancear(struct Node *node, int valor){
    int balance = balanceamento(node);
    if (balance > 1 && valor < node->esquerda->valor) {
        return direitaRotate(node); 
    }
    if (balance < -1 && valor > node->direita->valor) {
        return esquerdaRotate(node); 
    }
    if (balance < -1 && valor > node->direita->valor) {
        return esquerdaRotate(node); 
    }
    if (balance > 1 && valor > node->esquerda->valor) { 
        node->esquerda =  esquerdaRotate(node->esquerda); 
        return direitaRotate(node); 
    } 
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
    node->altura = 1 + max(altura(node->esquerda), 
                        altura(node->direita)); 
  
    /* 3. Obtem o fator de balanceamento da raiz 
    para observar se a árvore continua balanceada */
    //int balance = balanceamento(node); 
  
    // Se a árvore está desbalanceada, então existem quatro casos possíveis
  
    /* Caso esquerda esquerda
        T1, T2, T3 e T4 são sub-árvores.
          z                                      y 
         / \                                   /   \
        y   T4     Rotação direita (z)        x      z
       / \          - - - - - - - - ->      /  \    /  \ 
      x   T3                               T1  T2  T3  T4
     / \
    T1   T2                                              */
    //if (balance > 1 && valor < node->esquerda->valor) {
    //    return direitaRotate(node); 
    //}
  
    /* Caso direita direita
      z                                y
     /  \                            /   \ 
    T1   y   Rotação esquerda (z)   z      x
        /  \   - - - - - - - ->    / \    / \
       T2   x                     T1  T2 T3  T4
           / \
         T3  T4                                  */
    // if (balance < -1 && valor > node->direita->valor) {
    //     return esquerdaRotate(node); 
    // }

    /* Caso esquerda direita
         z                               z                              x
        / \                            /   \                           /  \ 
       y   T4  Rotação esquerda (y)   x    T4  Rotação direita (z)   y      z
      / \      - - - - - - - - ->    /  \       - - - - - - - ->    / \    / \
    T1   x                          y    T3                       T1  T2 T3  T4
        / \                        / \
      T2   T3                    T1   T2                                     */
    // if (balance > 1 && valor > node->esquerda->valor) { 
    //     node->esquerda =  esquerdaRotate(node->esquerda); 
    //     return direitaRotate(node); 
    // } 
  
    /* Caso direita esquerda
       z                            z                            x
      / \                          / \                          /  \ 
    T1   y   Right Rotate (y)    T1   x      Left Rotate(z)   z      y
        / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \    / \
       x   T4                      T2   y                  T1  T2  T3  T4
      / \                              /  \
    T2   T3                           T3   T4                             */
    // if (balance < -1 && valor < node->direita->valor) { 
    //     node->direita = direitaRotate(node->direita); 
    //     return esquerdaRotate(node); 
    // } 
  
    /* retorna o ponteiro (não-atualizado) para a raiz */
    node = balancear(node, valor);
    return node; 
} 

// Função para remover a raiz
struct Node *removeRaiz(struct Node *raiz){
    // Caso de apenas 1 filho
    if (raiz->esquerda == NULL){
        if (raiz->direita != NULL){
            raiz = raiz->direita;
            return raiz;
        }
        return NULL;
    }
    
    struct Node *q = raiz->esquerda;

    while (q->direita != NULL){
        q = q->direita;
    }
    raiz->valor = q->valor;
    raiz->esquerda = removeNode(raiz->esquerda, q->valor);
    return raiz;
}

// Função de remover um nó
struct Node *removeNode(struct Node *raiz, int x){
    if (raiz == NULL) return NULL;

    if (raiz->valor > x){
        raiz->esquerda = removeNode(raiz->esquerda, x);
    } else if (raiz->valor < x){
        raiz->direita = removeNode(raiz->direita, x);
    } else {
        raiz = removeRaiz(raiz);
    }

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
    
    /* A árvore AVL construída será
              30 
             /  \ 
            20   40 
           /  \    \ 
         10  25    50 
    
    A saida correta em pre-ordem é 30 20 10 25 40 50 */
    
    printf("Os elementos da arvore, em ordem, sao:\n"); 
    inOrder(raiz); 
    printf("\n");

    printf("\nOs elementos da arvore, em pre ordem, sao:\n"); 
    preOrder(raiz); 
    printf("\n");

    raiz = removeNode(raiz, 20);
    printf("\nOs elementos da arvore, em pre ordem, sao:\n"); 
    preOrder(raiz); 
    printf("\n");

    return 0; 
} 
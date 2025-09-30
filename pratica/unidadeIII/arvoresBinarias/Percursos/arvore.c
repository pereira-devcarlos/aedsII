#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
 
// Cria um novo nó na árvore
struct node* novo_no(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->valor = item;
    temp->esquerda = temp->direita = NULL;
    return temp;
}
 
// Inserir novo nó com determinado
// valor na árvore binária
struct node* inserir(struct node* node, int valor) {
    // Se a árvore é vazia, então cria um novo nó
    if (node == NULL) {
        return novo_no(valor);
    }
 
    // Caso contrário, faz uma busca pelo local adequado de inserção
    if (valor < node->valor) {
        node->esquerda = inserir(node->esquerda, valor);
    } else if (valor > node->valor) {
        node->direita = inserir(node->direita, valor);
    }
    
    // Retorna o ponteiro para o nó
    return node;
}
 
// Procura por um valor na árvore
struct node* buscar(struct node* root, int valor) {
    // Caso base - a raiz é vazia ou o valor está na raiz
    if (root == NULL || root->valor == valor) {
        return root;
    }

    // Valor é maior que a raiz
    if (root->valor < valor) {
        return buscar(root->direita, valor);
    }

    // Valor é menor que a raiz
    return buscar(root->esquerda, valor);
}

// Remover um determinado nó da árvore
struct node* remover(struct node* root, int valor) {
    if (buscar(root, valor) == NULL) {
        printf("Erro: no com valor %d nao foi encontrado!\n", valor);
        return root;
    }

    // Nó temporário para armazenar o nó a ser removido
    struct node* temp = NULL;

    // Caso base
    if (root == NULL) {
        return root;
    }

    // Caso o valor a ser removido seja menor que a raiz
    if (valor < root->valor) {
        root->esquerda = remover(root->esquerda, valor);
    }
    // Caso o valor a ser removido seja maior que a raiz
    else if (valor > root->valor) {
        root->direita = remover(root->direita, valor);
    }
    // Caso o valor seja igual ao da raiz, então este é o nó a ser removido
    else {
        // Nó com apenas um filho ou nenhum filho
        if (root->esquerda == NULL) {
            temp = root->direita;
            free(root);
            return temp;
        } else if (root->direita == NULL) {
            temp = root->esquerda;
            free(root);
            return temp;
        }

        // Nó com dois filhos: obtém o sucessor em ordem (menor na subárvore direita)
        temp = root->direita;
        while (temp && temp->esquerda != NULL) {
            temp = temp->esquerda;
        }

        // Copia o valor do sucessor em ordem para este nó
        root->valor = temp->valor;

        // Remove o sucessor em ordem
        root->direita = remover(root->direita, temp->valor);
    }
    return root;
}

// Imprimir a árvore em ordem
void imprimir_pre_ordem(struct node* root) {
    if (root != NULL) {
        printf("\n%d ", root->valor);
        imprimir_pre_ordem(root->esquerda);
        imprimir_pre_ordem(root->direita);
    }
}

// Imprimir a árvore em ordem
void imprimir_em_ordem(struct node* root) {
    if (root != NULL) {
        imprimir_em_ordem(root->esquerda);
        printf("\n%d", root->valor);
        imprimir_em_ordem(root->direita);
    }
}

// Imprimir a árvore em ordem
void imprimir_pos_ordem(struct node* root) {
    if (root != NULL) {
        imprimir_pos_ordem(root->esquerda);
        imprimir_pos_ordem(root->direita);
        printf("\n%d ", root->valor);
    }
}

void imprimir_em_niveis(struct node* root){
    if(root != NULL){
        if(root->esquerda){
            printf("\n%d", root->esquerda->valor);
        }
        if(root->direita){
            printf("\n%d", root->direita->valor);
        }

        imprimir_em_niveis(root->esquerda);
        imprimir_em_niveis(root->direita);
    }
}


int main() {
    // Define a árvore como uma estrutura vazia
    struct node* root = NULL;

    // Insere o nó inicial (raiz)
    root = inserir(root, 50);

    // Insere outros nós
    inserir(root, 8);
    inserir(root, 3);
    inserir(root, 10);
    inserir(root, 1);
    inserir(root, 6);
    inserir(root, 14);
    inserir(root, 4);
    inserir(root, 7);
    inserir(root, 13);

 
    // Testando as funções de percursos
    
    // Imprimir a árvore pré ordem
    printf("\nImpressão em pré ordem: ");
    imprimir_pre_ordem(root);

    // Imprimir a árvore em ordem
    printf("\nImpressão em ordem: ");
    imprimir_em_ordem(root);

    // Imprimir a árvore pós ordem
    printf("\nImpressão em pós ordem: ");
    imprimir_pos_ordem(root);
    
    // Imprimir a árvore em niveis
    printf("\nImpressão em niveis: ");
    imprimir_em_niveis(root);

    return 0;
}
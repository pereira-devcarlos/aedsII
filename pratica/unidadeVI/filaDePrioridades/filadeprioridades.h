#ifndef _H_FILADEPRIORIDADES_
#define _H_FILADEPRIORIDADES_

// Estrutura de Dados do Jogador
typedef struct {
    char nome[50];
    int idade; // Prioridade
} Jogador;

// Estrutura para Nó de Lista Encadeada
typedef struct node {
    Jogador jogador;
    struct node* next;
} Node;


// Vetor Ordenado
// Mantido em ordem CRESCENTE de idade (menor para maior)
typedef struct {
    Jogador* dados;
    int tamanho;
    int capacidade;
} VetorOrdenado;




#endif // _H_FILADEPRIORIDADES_


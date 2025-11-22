#ifndef _H_ABB
#define _H_ABB

// Estrutura do nó da árvore
typedef struct no {
    int valor;
    struct no *esq, *dir;
} No;

#endif // _H_ABB
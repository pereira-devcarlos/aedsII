#ifndef _H_ABB
#define _H_ABB

// Estrutura do nó da árvore
typedef struct no {
    int valor;
    struct no *esq, *dir;
} No;

No *alocarNo(int valor);
No *insertNo(No *raiz, No *noInserir);
void preOrdem(No *raiz);
void emOrdem(No *raiz);

#endif // _H_ABB
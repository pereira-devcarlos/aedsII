#ifndef _H_ABB
#define _H_ABB

// Estrutura do nó da árvore
typedef struct no {
    int valor;
    struct no *esq, *dir;
} No;

No *alocarNo(int valor);
No *insertNo(No *raiz, No *noInserir);
No *buscaNo(No *raiz, int valor);
No *buscaPai(No *raiz, int valor);
No *removeRaiz(No *raiz);
No *removerNo(No *raiz, int valor);
void preOrdem(No *raiz);
void emOrdem(No *raiz);

#endif // _H_ABB
#ifndef _H_FILA
#define _H_FILA

// Nó da fila
typedef struct no {
    int valor;
    struct no* prox;
} No;

struct fila* criar_fila();
bool ehVazia(struct fila* fila);
void push(struct fila* fila, int item);
No* pop(struct fila* fila);
No* obtem_elemento(struct fila* fila);

#endif // _H_FILA
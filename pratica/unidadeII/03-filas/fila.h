#ifndef _H_PILHA
#define _H_PILHA

struct fila* criar_fila(int tamanho);
bool ehCheia(struct fila* fila);
bool ehVazia(struct fila* fila);
void push(struct fila* fila, int item);
int pop(struct fila* fila);
int obtem_elemento(struct fila* fila);

#endif // _H_PILHA
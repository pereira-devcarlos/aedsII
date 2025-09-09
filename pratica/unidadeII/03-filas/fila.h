#ifndef _H_FILA
#define _H_FILA

struct fila* criar_fila(int tamanho);
bool ehCheia(struct fila* fila);
bool ehVazia(struct fila* fila);
void push(struct fila* fila, int item);
int pop(struct fila* fila);
int obtem_elemento(struct fila* fila);

#endif // _H_FILA
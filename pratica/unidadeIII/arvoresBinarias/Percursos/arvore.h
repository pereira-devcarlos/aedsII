#ifndef _H_ARVORE
#define _H_ARVORE

struct node {
    int valor;
    struct node *esquerda, *direita;
};

struct node* novo_no(int item);
struct node* inserir(struct node* node, int valor);
struct node* buscar(struct node* root, int valor);
struct node* remover(struct node* root, int valor);
void imprimir_pre_ordem(struct node* root);
void imprimir_em_ordem(struct node* root);
void imprimir_pos_ordem(struct node* root);

#endif // _H_ARVORE
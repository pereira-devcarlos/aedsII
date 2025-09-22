#ifndef _H_LISTA
#include <stdbool.h>
#define _H_LISTA

struct listaDupla;
void inserir_fim(struct listaDupla *lista, int elemento);
void inserir_inicio(struct listaDupla *lista, int elemento);
void inserir_posicao(struct listaDupla *lista, int elemento, int pos);
void apagar(struct listaDupla *lista, int elemento);
void apagar_inicio(struct listaDupla *lista);
void apagar_fim(struct listaDupla *lista);
void apagar_posicao(struct listaDupla *lista, int pos);
bool ehVazia(struct listaDupla *lista);
int obter_primeiro(struct listaDupla *lista);
int obter_ultimo(struct listaDupla *lista);
int obter_posicao(struct listaDupla *lista, int pos);
void imprimir(struct listaDupla *lista);

#endif // _H_LISTA
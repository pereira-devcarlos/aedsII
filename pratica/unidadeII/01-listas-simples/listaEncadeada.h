#ifndef _H_LISTA
#define _H_LISTA

void inserir_fim(int);
void inserir_inicio(int);
void inserir_posicao(int elemento, int pos);
void apagar(int);
void apagar_inicio(void);
void apagar_fim(void);
void apagar_posicao(int pos);
bool ehVazia(void);
int obter_primeiro(void);
int obter_ultimo(void);
int obter_posicao (int pos);
void imprimir();

#endif // _H_LISTA
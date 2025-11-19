#ifndef _H_HASH_
#define _H_HASH_

enum Estado {VAZIO, PREENCHIDO, REMOVIDO};

struct Item {
    int valor;
    enum Estado estado;
};

struct Hash {
    struct Item* items;   /* vetor de items da hash */
}; 

/* Cria uma hash*/
struct Hash* criar_hash(int tamanho);

/* Insere um novo elemento na hash */
void hash_insere(struct Hash* hash, struct Item item);

/* Remove um elemento da hash de acordo com sua chave */
void hash_remove(struct Hash* hash, struct Item item);

/* Obtém um item da hash */
struct Item busca(struct Hash* hash, struct Item item);

/* Função de hashing */
int hashing(int chave);

#endif // _H_HASH_
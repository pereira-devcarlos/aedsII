#ifndef _H_HASH_
#define _H_HASH_

#define MAX 10

// Estrutura do Heap
struct Heap {
    int dados[MAX];
    int tamanho;
};

// Estrutura do Hash (guarda índice do valor no heap)
struct Hash {
    int indices[MAX]; // indices[valor] = índice do valor no heap
    int estado[MAX];  // 0 = vazio, 1 = ocupado
};

// Inicializa heap
void heap_init(struct Heap* h);

// Inicializa hash
void hash_init(struct Hash* hash);

// Troca elementos no heap e atualiza hash
void troca(struct Heap* h, struct Hash* hash, int i, int j);

// Insere no heap e atualiza hash
void heap_insere(struct Heap* h, struct Hash* hash, int valor);

// Remove o topo do heap e atualiza hash
int heap_remove(struct Heap* h, struct Hash* hash);

// Busca índice do valor no heap usando hash
int heap_busca(struct Hash* hash, int valor);

// Imprime heap
void heap_imprime(struct Heap* h);

// Imprime hash
void hash_imprime(struct Hash* hash);

#endif // _H_HASH_
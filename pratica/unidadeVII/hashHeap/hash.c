#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

// Inicializa Heap
void heap_init(struct Heap* h) {
    h->tamanho = 0;
}

// Inicializa Hash
void hash_init(struct Hash* hash) {
    for (int i = 0; i < MAX; i++) {
        hash->indices[i] = -1;
        hash->estado[i] = 0;
    }
}

// Troca elementos no heap e atualiza hash
void troca(struct Heap* h, struct Hash* hash, int i, int j) {
    int tmp = h->dados[i];
    h->dados[i] = h->dados[j];
    h->dados[j] = tmp;
    // Atualiza índices no hash
    hash->indices[h->dados[i]] = i;
    hash->indices[h->dados[j]] = j;
}

// Insere no heap e atualiza hash
void heap_insere(struct Heap* h, struct Hash* hash, int valor) {
    if (h->tamanho == MAX) {
        printf("Heap cheio!\n");
        return;
    }
    int i = h->tamanho++;
    h->dados[i] = valor;
    hash->indices[valor] = i;
    hash->estado[valor] = 1;
    // Corrige acima
    while (i > 0 && h->dados[(i-1)/2] < h->dados[i]) {
        troca(h, hash, i, (i-1)/2);
        i = (i-1)/2;
    }
}

// Remove o topo do heap e atualiza hash
int heap_remove(struct Heap* h, struct Hash* hash) {
    if (h->tamanho == 0) {
        printf("Heap vazio!\n");
        return -1;
    }
    int topo = h->dados[0];
    hash->estado[topo] = 0;
    hash->indices[topo] = -1;
    h->dados[0] = h->dados[--h->tamanho];
    hash->indices[h->dados[0]] = 0;
    // Corrige abaixo
    int i = 0;
    while (1) {
        int esq = 2*i+1, dir = 2*i+2, maior = i;
        if (esq < h->tamanho && h->dados[esq] > h->dados[maior]) maior = esq;
        if (dir < h->tamanho && h->dados[dir] > h->dados[maior]) maior = dir;
        if (maior == i) break;
        troca(h, hash, i, maior);
        i = maior;
    }
    return topo;
}

// Busca valor no heap usando hash
int heap_busca(struct Hash* hash, int valor) {
    if (valor < 0 || valor >= MAX) return -1;
    if (hash->estado[valor] == 1)
        return hash->indices[valor]; // retorna índice no heap
    return -1; // não encontrado
}

// Imprime heap
void heap_imprime(struct Heap* h) {
    printf("Heap: ");
    for (int i = 0; i < h->tamanho; i++) {
        printf("%d ", h->dados[i]);
    }
    printf("\n");
}

// Imprime hash
void hash_imprime(struct Hash* hash) {
    printf("Hash (valor:indice): ");
    for (int i = 0; i < MAX; i++) {
        if (hash->estado[i] == 1)
            printf("%d:%d ", i, hash->indices[i]);
    }
    printf("\n");
}

int main() {
    struct Heap heap;
    struct Hash hash;
    heap_init(&heap);
    hash_init(&hash);

    // Teste de inserção
    heap_insere(&heap, &hash, 5);
    heap_insere(&heap, &hash, 8);
    heap_insere(&heap, &hash, 3);
    heap_insere(&heap, &hash, 9);
    heap_insere(&heap, &hash, 1);

    heap_imprime(&heap);
    hash_imprime(&hash);

    // Teste de busca
    int valor = 8;
    int idx = heap_busca(&hash, valor);
    if (idx != -1)
        printf("Valor %d está no índice %d do heap\n", valor, idx);
    else
        printf("Valor %d não está no heap\n", valor);

    // Teste de remoção
    printf("Removendo topo do heap: %d\n", heap_remove(&heap, &hash));
    heap_imprime(&heap);
    hash_imprime(&hash);

    // Teste de busca após remoção
    valor = 9;
    idx = heap_busca(&hash, valor);
    if (idx != -1)
        printf("Valor %d está no índice %d do heap\n", valor, idx);
    else
        printf("Valor %d não está no heap\n", valor);

    return 0;
}
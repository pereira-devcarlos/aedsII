#include <stdio.h> 
#include <stdlib.h> 
#include "hash.h"

int M;
int contador = 0;

struct Hash* criar_hash(int tamanho) {
    M = tamanho;
    struct Hash* hash = (struct Hash*) malloc(sizeof(struct Hash));
    hash->items = (struct Item*) malloc(tamanho*sizeof(struct Item));

    // Definindo todas as posições da tabela como Vazias
    for (int i = 0; i < M; i++){
        hash->items[i].estado = VAZIO;
    }
    return hash;
}

void hash_insere(struct Hash* hash, struct Item item) {
    if (contador == M){
        printf("\nErro: tabela cheia!");
        return;
    }
    
    int hashInt = hashing(item.valor);
    for (int i = 0; i < M; i++){
        int pos = (hashInt + i) % M;
        if (hash->items[pos].estado != PREENCHIDO){
            hash->items[pos] = item;
            hash->items[pos].estado = PREENCHIDO;
            contador++;
            return;
        }
    }
}

void hash_remove(struct Hash* hash, struct Item item) {
    if (contador == 0){
        printf("\nErro: tabela vazia!");
        return;
    }

    struct Item newItem;
    newItem.valor = 0;
    newItem.estado = REMOVIDO;
    
    int hashInt = hashing(item.valor);
    // Caso 1: não houver nenhuma inserção se quer na posição
    if (hash->items[hashInt].estado == VAZIO){
        printf("\nItem nao encontrado!");
        return;
    }
    
    // Caso 2: procurar linearmente na tabela
    for (int i = 0; i < M; i++){
        int pos = (hashInt + i) % M;
        if (hash->items[pos].estado == PREENCHIDO && hash->items[pos].valor == item.valor){
            hash->items[pos] = newItem;
            contador--;
            return;
        }           
    }   
}

struct Item busca(struct Hash* hash, struct Item item) {
    if (contador == 0){
        printf("\nErro: tabela vazia!");
        return;
    }
    
    int hashInt = hashing(item.valor);
    
    // Caso 1: não houver nenhuma inserção se quer na posição
    if (hash->items[hashInt].estado == VAZIO){
        printf("\nItem nao encontrado!");

        struct Item noItem;
        noItem.valor = -1;
        noItem.estado = VAZIO;
        return noItem;
    }

    for (int i = 0; i < M; i++){
        int pos = (hashInt + i) % M;
        if (hash->items[pos].estado == PREENCHIDO && hash->items[pos].valor == item.valor){
            return hash->items[pos];
        }
    }
}

int hashing(int chave) {
    return (chave % M);
}

int main() { 
    int n;
    /* Cria hash com 20 posições */
    struct Hash* hash = criar_hash(10);
    struct Item item;
    do {
        printf("\n\n\n******************** Escolha a opção *******************");
        printf("\n1.Inserir item");
        printf("\n2.Remover item");
        printf("\n3.Obter item");
        printf("\n0.Sair");
        printf("\nEntre sua opção : ");
        scanf("%d",&n);
        switch(n) {
            case 1: printf("\nDigite o item ");
                    scanf("%d",&item.valor);
                    hash_insere(hash, item);
                    break;
            case 2: printf("\nDigite o item ");
                    scanf("%d",&item.valor);
                    hash_remove(hash, item);
                    break;
            case 3: printf("\nDigite o item ");
                    scanf("%d",&item.valor);
                    item = busca(hash, item);
                    break;
            case 0: exit(0);
                    break;
            default: printf("\n Opção errada!");
                    break;
            }
        } while(1);
    
}
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct node {
    int key;
    struct node* next;
}Node;

int keyHash(int key){
    return key % TABLE_SIZE;
}

Node* createNode(int key){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

void insert(Node* table[], int key){
    int index = keyHash(key);
    Node* newNode = createNode(key);
    
    if (table[index] == NULL){
        table[index] = newNode;
    } else {
        Node* aux = table[index];
        while (aux->next != NULL){
            aux = aux->next;
        }
        aux->next = newNode;
    }
}

Node *search(Node *table[], int key){
    int index = keyHash(key);
    Node* aux = table[index];
    
    while (aux != NULL){
        if (aux->key == key){
            return aux;
        }
        aux = aux->next;
    }
    return NULL;
}

Node *removeKey(Node *table[], int key){
    int index = keyHash(key);

    // Nós auxiliares para percorrer a lista
    Node *aux = table[index];
    Node *prev = NULL;

    while (aux != NULL){
        if (aux->key == key){
            // Caso especial: remoção do primeiro nó da lista
            if (prev == NULL){
                table[index] = aux->next;
            } else {
                // Remoção de um nó que não é o primeiro
                prev->next = aux->next;
            }
            return aux;
        }
        // "Avança na lista"
        prev = aux;
        aux = aux->next;
    }
    return NULL;
}

int main(){
    Node* hashTable[TABLE_SIZE] = {NULL};

    return 0;
}

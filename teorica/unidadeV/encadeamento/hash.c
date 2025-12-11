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

int main(){
    Node* hashTable[TABLE_SIZE] = {NULL};
    
    return 0;
}

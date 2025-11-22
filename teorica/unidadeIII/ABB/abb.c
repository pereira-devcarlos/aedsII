#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

// Fução para alocar um novo nó na memória
No *alocarNo(int valor){
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->dir = NULL;
    novo->esq = NULL;
}



int main(){
    
    return 0;
}

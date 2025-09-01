#include<stdio.h>
#include<stdlib.h>

typedef struct no_ {
    //usada para indexar conteúdo.
    //deve ser única em todo o
    //vetor
    int chave;

    //qualquer coisa que eu queira
    //guardar. Ex: info. útil.
    int valor;

    struct no_* prox;
} no ;

no * ptlista;

void busca_enc(int x, no ** ant, no ** pont){
    *ant = ptlista;
    *pont = NULL;
    no * ptr = (*ptlista).prox;

    while(ptr != NULL){
        if((*ptr).chave < x){
            *ant = ptr;
            ptr = (*ptr).prox;
        }else{
            if((*ptr).chave == x){
                *pont = ptr;
            }
            ptr = NULL;
        }
    }
}

int insere_enc(no * no_inserir){
    int valor_retorno = -1;
    no * ant;
    no * pont;
    busca_enc((*no_inserir).chave, &ant, &pont);
    if(pont == NULL){
        (*no_inserir).prox = (*ant).prox;
        (*ant).prox = no_inserir;
        valor_retorno = 0;
    }
    return valor_retorno;
}


void main(){
    ptlista = (no*) malloc(sizeof(no));
    (*ptlista).prox = NULL;
    //OU
    //ptlista->prox = NULL;

    no * no_inserir = (no*) malloc(sizeof(no));
    (*no_inserir).chave = 2;
    (*no_inserir).valor = 2;
    (*no_inserir).prox = NULL;
    //printf("%d\n",insere_enc(no_inserir));
    
    no_inserir = (no*) malloc(sizeof(no));
    (*no_inserir).chave = 5;
    (*no_inserir).valor = 5;
    (*no_inserir).prox = NULL;
    //printf("%d\n",insere_enc(no_inserir));

    no * ant;
    no * pont;
    //testando a busca...
    int chave_procurar = 2;
    printf("elemento sendo buscado: %d\n", chave_procurar);

    busca_enc(chave_procurar, &ant, &pont);
    if(pont != NULL){
        printf("Elemento encontrado!\n\n");
    }else{
        printf("Elemento não encontrado!\n\n");
    }

    //testando a busca...
    chave_procurar = 5;
    
    busca_enc(chave_procurar, &ant, &pont);
    printf("elemento sendo buscado: %d\n", chave_procurar);

    busca_enc(chave_procurar, &ant, &pont);
    if(pont != NULL){
        printf("Elemento encontrado!\n\n");
    }else{
        printf("Elemento não encontrado!\n\n");
    }

    //testando a busca...
    chave_procurar = 7;
    printf("elemento sendo buscado: %d\n", chave_procurar);

    busca_enc(chave_procurar, &ant, &pont);
    if(pont != NULL){
        printf("Elemento encontrado!\n\n");
    }else{
        printf("Elemento não encontrado!\n\n");
    }

    //testando a busca...
    chave_procurar = 1;
    printf("elemento sendo buscado: %d\n", chave_procurar);

    busca_enc(chave_procurar, &ant, &pont);
    if(pont != NULL){
        printf("Elemento encontrado!\n\n");
    }else{
        printf("Elemento não encontrado!\n\n");
    }

    //testando a busca...
    chave_procurar = 3;
    printf("elemento sendo buscado: %d\n", chave_procurar);

    busca_enc(chave_procurar, &ant, &pont);
    if(pont != NULL){
        printf("Elemento encontrado!\n\n");
    }else{
        printf("Elemento não encontrado!\n\n");
    }

    //A fazer:
    // - implementar a remoção
    // - implementar a impressão
    // - implementar a liberação de memória (ao encerrar)
    // - ajustar o código de modo a ficar "utilizável",
    // com menu para buscar, inserir, remover, imprimir e encerrar.
    free(ptlista);
}
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esq, *dir;
} No;

// Função de inserção com Retorno
No* insere (No *raiz, int valor) {
    // Verificar se a raiz é NULL
    if (raiz == NULL){
        No *novo = (No*) malloc(sizeof(No));
        novo->valor = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    } else {
        if (valor < raiz->valor){
            raiz->esq = insere(raiz->esq, valor);
        } else {
            raiz->dir = insere(raiz->dir, valor);
        }
        return raiz;                   
    }
}

// Função de Buscar um nó
No* busca (No* raiz, int x){
    if (raiz == NULL || raiz->valor == x){
        return raiz;
    } else {
        if (x < raiz->valor){
            raiz = busca(raiz->esq, x);
        } else {
            raiz = busca(raiz->dir, x);
        }        
        return raiz;
    }
}

// Função de Buscar o pai
No* buscaPai (No* raiz, int x) {
    // Verificando se existe o nó a ser buscado o pai
    if (!busca(raiz, x)) return NULL;
    
    if (raiz == NULL || raiz->esq->valor == x || raiz->dir->valor == x){
        return raiz;
    } else {
        if (x < raiz->valor){
            raiz = buscaPai(raiz->esq, x);
        } else {
            raiz = buscaPai(raiz->dir, x);
        }        
        return raiz;
    }
}

// Função para Remover a raiz de uma arvore
No* removeRaiz(No* raiz){
    No* tmp = raiz;
    // Verificando se existe nó a esquerda
    if (raiz->esq == NULL){
        tmp = raiz->dir;
        free(raiz);
        return tmp;
    }
    // Verificando se existe nó a direita
    if (raiz->dir == NULL){
        tmp = raiz->esq;
        free(raiz);
        return tmp;
    }

    No* p = raiz;
    No* f = raiz->esq;
    // Buscando o maior nó a esqueda da raiz removida 
    while (f->dir != NULL){
        p = f;
        f = f->dir;
    }
    
    // Substituindo a raiz pelo nó novo
    raiz->valor = f->valor;

    // Removendo o nó folha que virou raiz
    if (p->dir == f){
        p->dir = removeRaiz(f);
    } else {
        p->esq = removeRaiz(f);
    }
    return raiz;
}

// Função para remover um nó qualquer
No* removeNo(No* raiz, int x){
    // verifica se o nó existe na arvore
    No* n = busca(raiz, x);
    if (n){
        // Verifica se o nó possui pai
        No* pai = buscaPai(raiz, x);
        if (pai){
            if (pai->dir == n){
                // Nó a ser removido é filho a direita
                pai->dir = removeRaiz(n);
            }
            else {
                // Nó a ser removido é filho a esquerda
                pai->esq = removeRaiz(n);
            }
        }
        else {
            // Caso não possui um pai, o próprio nó é a raiz 
            raiz = removeRaiz(raiz);
        }
    }
    return raiz;
}

// Funções de impressões: pré ordem, em ordem e pós ordem 
void preOrdem (No *raiz) {
    if (raiz == NULL) return;
    printf("%d\n", raiz->valor);
    preOrdem(raiz->esq);
    preOrdem(raiz->dir);
}
void emOrdem (No *raiz) {
    if (raiz == NULL) return;
    emOrdem(raiz->esq);
    printf("%d\n", raiz->valor);
    emOrdem(raiz->dir);
}
void posOrdem (No *raiz) {
    if (raiz == NULL) return;
    posOrdem(raiz->esq);
    posOrdem(raiz->dir);
    printf("%d\n", raiz->valor);
}

// Menu de opções
void exibirMenu(){
    printf("\n\n=============== Menu ===============");
    printf("\n[1]- Inserir no na arvore");
    printf("\n[2]- Remover no da arvore");
    printf("\n[3]- Buscar um no da arvore");
    printf("\n[4]- Buscar o pai de um no da arvore");
    printf("\n[5]- Exibir arvore em pre ordem");
    printf("\n[6]- Exibir arvore em ordem");
    printf("\n[7]- Exibir arvore em pos ordem");
    printf("\n[0]- Encerrar programa");
    printf("\n=> Digite a opcao desejada: ");
}

int main(){
    No *raiz = NULL;

    int opcao=-1;
    while (opcao != 0){
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao){
        case 1:{
            int numInsert;
            printf("\n*************** Insercao ***************");
            printf("\nDigite o valor a ser inserido na arvore: ");
            scanf("%d", &numInsert);

            raiz = insere(raiz, numInsert);
            printf("\nNo com valor %d, foi inserido com sucesso!", numInsert);
            break;
        }
        case 2:{
            int numRemove;
            printf("\n*************** Remocao ***************");
            printf("\nDigite o valor a ser removido da arvore: ");
            scanf("%d", &numRemove);

            No* verNo = busca(raiz, numRemove);
            if (verNo){
                raiz = removeNo(raiz, numRemove);
                printf("\nNo com valor %d, foi removido com sucesso!", numRemove);
            } else {
                printf("\nErro: no inexistente com o valor %d", numRemove);
            }
            break;
        }
        case 3:{
            int numBusca;
            printf("\n**************** Busca ****************");
            printf("\nDigite o valor a ser buscado da arvore: ");
            scanf("%d", &numBusca);
            No* resultBusca = busca(raiz, numBusca);

            if (resultBusca) printf("\nNo com o valor %d, foi encontrado!", numBusca);
            else printf("\nNo com o valor %d, nao foi encontrado!", numBusca);
            break;
        }
        case 4:{
            int numBuscaPai;
            printf("\n*************** Busca Pai ***************");
            printf("\nDigite o valor a ser buscado o pai do no: ");
            scanf("%d", &numBuscaPai);

            No* verNo = busca(raiz, numBuscaPai);
            if (verNo){
                No* resultBuscaPai = buscaPai(raiz, numBuscaPai);
                if (resultBuscaPai->valor != numBuscaPai){
                    printf("\nNo com valor %d, pai: %d", numBuscaPai, resultBuscaPai->valor);
                } else {
                    printf("\nNo com valor %d, nao possui pai (eh a propria raiz)", numBuscaPai);
                }
            } else {
                printf("\nErro: no inexistente com o valor %d", numBuscaPai);
            }

            break;
        }
        case 5:{
            printf("\n*************** Pre Ordem ***************\n");
            preOrdem(raiz);
            break;
        }
        default:
            printf("\nOpcao invalida! Tente novamente.");
            break;
        }
    }

    return 0;
}

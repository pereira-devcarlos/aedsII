#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore
typedef struct no {
    int valor, altura;
    struct no *dir, *esq;
} No;

// Prototipos de Funções
No* removeNo(No* raiz, int valor);

// Função para criar um novo nó
No* criarNo(int valor){
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->altura = 1;  // Altura inicial do nó é 1
    novo->dir=NULL;
    novo->esq=NULL;
    return novo;
}

int maior(int a, int b){
    if (a > b) return a;
    else return b;
}

// Função para retornar a altura de um nó
int altura(No* raiz){
    if (raiz == NULL) return 0;
    return raiz->altura;
}

// Função para atualizar a altura de um nó
void atualizarAltura(No* raiz) {
    if (raiz) {
        int esq = altura(raiz->esq);
        int dir = altura(raiz->dir);
        
        raiz->altura = maior(esq, dir) + 1;
    }
}

// Função para retornar o valor do FB
int fatorBalanceamento(No* raiz){
    if(raiz != NULL){
        return altura(raiz->esq) - altura(raiz->dir);
    }
    // Se não possuir a raiz
    return 0;
}

// Função de rotação para esquerda
No* rotacionaEsq(No* raiz){
    No* nova = raiz->dir;
    raiz->dir = nova->esq;
    nova->esq = raiz;

    // Atualiza as alturas dos nós
    atualizarAltura(raiz);
    atualizarAltura(nova);

    return nova;
}

// Função de rotação para direita
No* rotacionaDir(No* raiz){
    No* nova = raiz->esq;
    raiz->esq = nova->dir;
    nova->dir = raiz;

    // Atualiza as alturas dos nós
    atualizarAltura(raiz);
    atualizarAltura(nova);
    
    return nova;
}

// Função de rotação dupla para esquerda e direita
No* rotacionaEsqDir(No* raiz){
    raiz->esq = rotacionaEsq(raiz->esq);
    raiz = rotacionaDir(raiz);
    return raiz;
}

// Função de rotação dupla para direita e esquerda
No* rotacionaDirEsq(No* raiz){
    raiz->dir = rotacionaDir(raiz->dir);
    raiz = rotacionaEsq(raiz);
    return raiz;
}

// Função para balancear a árvore
No* balancear(No* raiz){
    // Armazena o fator de balanceamento
    int fator = fatorBalanceamento(raiz);

    // Verifica e aplica as rotações necessárias
    if (fator < -1 && fatorBalanceamento(raiz->dir) <= 0){
        raiz = rotacionaEsq(raiz);
    } else if (fator > 1 && fatorBalanceamento(raiz->esq) >= 0){
        raiz = rotacionaDir(raiz);
    } else if (fator > 1 && fatorBalanceamento(raiz->esq) < 0){
        raiz = rotacionaEsqDir(raiz);
    } else if (fator < -1 && fatorBalanceamento(raiz->dir) > 0){
        raiz = rotacionaDirEsq(raiz);
    }
    // Retorna a raiz possivelmente modificada
    return raiz;
}

// Função para inserir um valor na árvore binária de busca
No* insertArvore(No* raiz, int valor){
    // Se a árvore estiver vazia, cria um novo nó
    if (raiz == NULL){
        raiz = criarNo(valor);
    } else {
        // Caso contrário, insere recursivamente na esquerda ou direita
        if (valor < raiz->valor){
            raiz->esq = insertArvore(raiz->esq, valor);
        } else {
            raiz->dir = insertArvore(raiz->dir, valor);
        }
    }

    // Sempre atualizar a altura após a inserção
    atualizarAltura(raiz);
    
    // Verifica e se caso necessário, irá balancear a árvore
    raiz = balancear(raiz);

    return raiz;
}

// Função para buscar um nó da árvore
No* buscaNo(No* raiz, int valor){
    if (raiz == NULL || valor == raiz->valor){
        return raiz;
    } 
    
    if (valor < raiz->valor){
        return buscaNo(raiz->esq, valor);
    } else {
        return buscaNo(raiz->dir, valor);
    }
}

// Função para buscar um pai de um nó
No* buscaPai(No* raiz, int valor){
    if (raiz->esq->valor == valor || raiz->dir->valor == valor){
        return raiz;
    }

    if (valor < raiz->valor){
        return buscaPai(raiz->esq, valor);
    } else {
        return buscaPai(raiz->dir, valor);
    }
}

// Função para remover a raiz da arvore
No* removeRaiz(No* raiz){
    if(raiz == NULL) return raiz;

    if (raiz->esq == NULL){
        // Se não existir nó a esquerda
        // Nó à direita assume a raiz;
        if (raiz->dir != NULL){
            raiz = raiz->dir;
            atualizarAltura(raiz);
            raiz = balancear(raiz);
            return raiz;
        }    
        // Só existe a raiz, retorna null
        return NULL;
    }
    
    // Encontrar o maior da esquerda
    No* q = raiz->esq;
    while (q->dir != NULL){
        q = q->dir;
    }
        
    // Troca os valores 
    raiz->valor = q->valor;
    raiz->esq = removeNo(raiz->esq, q->valor);
    
    atualizarAltura(raiz);
    raiz = balancear(raiz);
    return raiz;
}

// Função para remover um nó qualquer da árvore
No* removeNo(No* raiz, int valor){
    if (raiz == NULL) return NULL;
    
    if (valor < raiz->valor){
        raiz->esq = removeNo(raiz->esq, valor);
    } else if (valor > raiz->valor){
        raiz->dir = removeNo(raiz->dir, valor);
    } else {
        raiz = removeRaiz(raiz);
    }

    atualizarAltura(raiz);
    raiz = balancear(raiz);
    return raiz;
}

// Funções de exibição da árvore 
void exibirPreOrdem(No* raiz){
    if (raiz == NULL) return;
    printf("%d ", raiz->valor);
    exibirPreOrdem(raiz->esq);
    exibirPreOrdem(raiz->dir);
}
void exibirEmOrdem(No* raiz){
    if (raiz == NULL) return;
    exibirEmOrdem(raiz->esq);
    printf("%d ", raiz->valor);
    exibirEmOrdem(raiz->dir);
}
void exibirPosOrdem(No* raiz){
    if (raiz == NULL) return;
    exibirPosOrdem(raiz->esq);
    exibirPosOrdem(raiz->dir);
    printf("%d ", raiz->valor);
}

void exibirMenu(){
    printf("\n=============== Menu ===============");
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
    // Criar nó raiz da árvore
    No* raiz=NULL;

    // Inicializar o loop com uma variável de opção
    int opcao=-1;
    while (opcao != 0){
        // Menu de opções
        exibirMenu();
        scanf("%d", &opcao);
        
        switch (opcao){
        case 1:{
            int numInsert;
            printf("\n************ Insercao ************");
            printf("\nDigite o valor a ser inserido na arvore: ");
            scanf("%d", &numInsert);

            raiz = insertArvore(raiz, numInsert);
            break;
        }
        case 2:{
            int numRemove;
            printf("\n************ Remocao ************");
            printf("\nDigite o valor a ser removido da arvore: ");
            scanf("%d", &numRemove);

            No* verNo = buscaNo(raiz, numRemove);
            if (verNo) raiz = removeNo(raiz, numRemove);
            else printf("\nErro: no inexistente com o valor %d", numRemove);
            
            break;
        }
        case 3:{
            int numBusca;
            printf("\n************* Busca *************");
            printf("\nDigite o valor a ser buscado da arvore: ");
            scanf("%d", &numBusca);
            No* resultBusca = buscaNo(raiz, numBusca);

            if (resultBusca) printf("\nNo com o valor %d, foi encontrado!", numBusca);
            else printf("\nNo com o valor %d, nao foi encontrado!", numBusca);
            break;
        }
        case 4:{
            int numBuscaPai;
            printf("\n********* Busca Pai *********");
            printf("\nDigite o valor a ser buscado o pai do no: ");
            scanf("%d", numBuscaPai);

            No* verNo = buscaNo(raiz, numBuscaPai);
            if (verNo){
                No* resultBuscaPai = buscaPai(raiz, numBuscaPai);
                printf("\nNo com valor %d, pai: %d", numBuscaPai, resultBuscaPai->valor);
            } else {
                printf("\nErro: no inexistente com o valor %d", numBuscaPai);
            }

            break;
        }
        case 5:{
            printf("\n********* Arvore Pre Ordem *********\n");
            exibirPreOrdem(raiz);
            break;
        }
        case 6:
            printf("\n********** Arvore em Ordem **********\n");
            exibirEmOrdem(raiz);
            break;
        case 0:
            printf("\nEncerrando programa...\n");
            break;
        default:
            printf("\nErro: opcao invalida!");
            break;
        }
    }
    
    return 0;
}

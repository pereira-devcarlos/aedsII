#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filadeprioridades.h"


// Vetor Ordenado
// Mantido em ordem CRESCENTE de idade (menor para maior)
VetorOrdenado* criarVetorOrdenado(int capacidadeInicial) {
    VetorOrdenado* v = (VetorOrdenado*)malloc(sizeof(VetorOrdenado));
    if (v == NULL) {
        fprintf(stderr, "Erro ao alocar VetorOrdenado\n");
        exit(1);
    }
    v->dados = (Jogador*)malloc(capacidadeInicial * sizeof(Jogador));
    if (v->dados == NULL) {
        fprintf(stderr, "Erro ao alocar dados do vetor\n");
        free(v);
        exit(1);
    }
    v->tamanho = 0;
    v->capacidade = capacidadeInicial;
    return v;
}

void destruirVetorOrdenado(VetorOrdenado* v) {
    free(v->dados);
    free(v);
}

// Inserção
void inserirVetorOrdenado(VetorOrdenado* v, Jogador j) {
    // Verificar redimensionamento
    if (v->tamanho == v->capacidade) {
        v->capacidade *= 2;
        v->dados = (Jogador*)realloc(v->dados, v->capacidade * sizeof(Jogador));
        if (v->dados == NULL) {
            fprintf(stderr, "Erro ao realocar dados do vetor\n");
            exit(1);
        }
    }

    // (Percorre do fim para o começo)
    int i = v->tamanho - 1;
    while (i >= 0 && v->dados[i].idade > j.idade) {
        v->dados[i + 1] = v->dados[i]; // Desloca item para a direita
        i--;
    }
    
    // Inserir na posição correta
    v->dados[i + 1] = j;
    v->tamanho++;
}

// Remoção
// Remove o de maior prioridade (maior idade), que está no FIM
Jogador removerVetorOrdenado(VetorOrdenado* v) {
    if (v->tamanho == 0) {
        fprintf(stderr, "Erro: Fila (vetor) vazia!\n");
        exit(1);
    }
    v->tamanho--;
    return v->dados[v->tamanho]; // Retorna o último elemento
}

ListaNaoOrdenada* criarListaNaoOrdenada() {
    ListaNaoOrdenada* l = (ListaNaoOrdenada*)malloc(sizeof(ListaNaoOrdenada));
    if (l == NULL) {
        fprintf(stderr, "Erro ao alocar ListaNaoOrdenada\n");
        exit(1);
    }
    l->head = NULL;
    return l;
}

void destruirListaNaoOrdenada(ListaNaoOrdenada* lista) {
    Node* current = lista->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(lista);
}

// Insere em qualquer lugar (vamos inserir no começo)
void inserirListaNaoOrdenada(ListaNaoOrdenada* l, Jogador j) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Erro ao alocar no (lista nao ordenada)\n");
        exit(1);
    }
    newNode->jogador = j;
    newNode->next = l->head;
    l->head = newNode;
}

// Remoção
// Precisa percorrer a lista toda para achar o de maior prioridade
Jogador removerListaNaoOrdenada(ListaNaoOrdenada* l) {
    if (l->head == NULL) {
        fprintf(stderr, "Erro: Fila (lista nao ordenada) vazia!\n");
        exit(1);
    }

    Node* maxNode = l->head;
    Node* prevMax = NULL;
    Node* current = l->head;
    Node* prev = NULL;

    // 1. Percorre a lista para achar o nó de maior idade
    while (current != NULL) {
        if (current->jogador.idade > maxNode->jogador.idade) {
            maxNode = current;
            prevMax = prev;
        }
        prev = current;
        current = current->next;
    }

    // 2. Remove o nó
    if (prevMax == NULL) { // O máximo era o primeiro (head)
        l->head = maxNode->next;
    } else {
        prevMax->next = maxNode->next;
    }

    Jogador j = maxNode->jogador;
    free(maxNode);
    return j;
}

ListaEncadeadaOrdenada* criarListaEncadeadaOrdenada() {
    ListaEncadeadaOrdenada* l = (ListaEncadeadaOrdenada*)malloc(sizeof(ListaEncadeadaOrdenada));
    if (l == NULL) {
        fprintf(stderr, "Erro ao alocar ListaEncadeadaOrdenada\n");
        exit(1);
    }
    l->head = NULL;
    return l;
}

void destruirListaEncadeadaOrdenada(ListaEncadeadaOrdenada* l) {
    Node* current = l->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(l);
}

// Inserção
// Acha a posição correta para manter a ordem (descrescente)
void inserirListaEncadeadaOrdenada(ListaEncadeadaOrdenada* l, Jogador j) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Erro ao alocar no (lista ordenada)\n");
        exit(1);
    }
    newNode->jogador = j;

    // Caso 1: Lista vazia ou novo nó é o de maior prioridade
    if (l->head == NULL || j.idade > l->head->jogador.idade) {
        newNode->next = l->head;
        l->head = newNode;
    } else {
    // Caso 2: Percorre a lista para achar a posição
        Node* current = l->head;
        while (current->next != NULL && current->next->jogador.idade > j.idade) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Remoção
// Remove o de maior prioridade (maior idade), que está no COMEÇO
Jogador removerListaEncadeadaOrdenada(ListaEncadeadaOrdenada* l) {
    if (l->head == NULL) {
        fprintf(stderr, "Erro: Fila (lista ordenada) vazia!\n");
        exit(1);
    }
    
    Node* temp = l->head;
    Jogador j = temp->jogador;
    l->head = l->head->next;
    free(temp);
    return j;
}


int main() {
    // Criar dados fictícios
    const int NUM_JOGADORES = 10;
    Jogador* dadosJogadores = (Jogador*)malloc(NUM_JOGADORES * sizeof(Jogador));
    if (dadosJogadores == NULL) {
        fprintf(stderr, "Erro ao alocar dados de teste\n");
        return 1;
    }

    // Preenche em ordem decrescente (pior caso para inserção ordenada)
    for (int i = 0; i < NUM_JOGADORES; i++) {
        sprintf(dadosJogadores[i].nome, "Jogador_%d", NUM_JOGADORES - i);
        dadosJogadores[i].idade = NUM_JOGADORES - i;
    }

    Jogador ultimoRemovido;

    // Testando Vetor Ordenado
    printf("Testando: Vetor Ordenado:\n");
    VetorOrdenado* filaVetor = criarVetorOrdenado(10);
    
    for (int i = 0; i < NUM_JOGADORES; i++) {
        inserirVetorOrdenado(filaVetor, dadosJogadores[i]);
    }
    for (int i = 0; i < NUM_JOGADORES; i++) {
        ultimoRemovido = removerVetorOrdenado(filaVetor);
    }
    printf("Vetor Ordenado concluido. Ultimo removido: %s (Idade: %d)\n\n", ultimoRemovido.nome, ultimoRemovido.idade);
    destruirVetorOrdenado(filaVetor);


    // Testando Lista Encadeada Ordenada
    printf("Testando: Lista Enc. Ordenada:\n");
    ListaEncadeadaOrdenada* filaListaOrd = criarListaEncadeadaOrdenada();

    for (int i = 0; i < NUM_JOGADORES; i++) {
        inserirListaEncadeadaOrdenada(filaListaOrd, dadosJogadores[i]);
    }
    for (int i = 0; i < NUM_JOGADORES; i++) {
        ultimoRemovido = removerListaEncadeadaOrdenada(filaListaOrd);
    }
    printf("Lista Enc. Ordenada concluida. Ultimo removido: %s (Idade: %d)\n\n", ultimoRemovido.nome, ultimoRemovido.idade);
    destruirListaEncadeadaOrdenada(filaListaOrd);


    // Testando Lista Não Ordenada
    printf("Testando: Lista Nao Ordenada:\n");
    ListaNaoOrdenada* filaListaNaoOrd = criarListaNaoOrdenada();

    for (int i = 0; i < NUM_JOGADORES; i++) {
        inserirListaNaoOrdenada(filaListaNaoOrd, dadosJogadores[i]);
    }
    for (int i = 0; i < NUM_JOGADORES; i++) {
        ultimoRemovido = removerListaNaoOrdenada(filaListaNaoOrd);
    }
    printf("Lista Nao Ordenada concluida. Ultimo removido: %s (Idade: %d)\n\n", ultimoRemovido.nome, ultimoRemovido.idade);
    destruirListaNaoOrdenada(filaListaNaoOrd);


    // Liberar dados de teste
    free(dadosJogadores);

    return 0;
}
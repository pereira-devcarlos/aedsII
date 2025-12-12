#include <stdio.h> 
#include <stdlib.h> 
#define TAM 10

struct Heap {
 int max;           /* tamanho maximo do heap */
 int pos;           /* proxima posicao disponivel no vetor */
 int* prioridade;   /* vetor das prioridades */
}; 


struct Heap* heap_inicializa(int max) {
    struct Heap* heap=(struct Heap*)malloc(sizeof(struct Heap));
    heap->max = max;
    heap->pos = 0;
    heap->prioridade=(int *)malloc(max*sizeof(int));
    return heap;
}

void troca(int a, int b, int* v) {
    int f = v[a];
    v[a] = v[b];
    v[b] = f;
}

void corrige_acima(struct Heap* heap, int pos) {
    int pai;
    while (pos > 0) {
        pai = (pos-1)/2;
        if (heap->prioridade[pai] < heap->prioridade[pos]) {
            troca(pos,pai,heap->prioridade);
        } else { 
            break;
        }
        pos = pai;
    }
}

void heap_insere(struct Heap* heap, int prioridade) {
    if (heap->pos < heap->max) {
        heap->prioridade[heap->pos]=prioridade;
        corrige_acima(heap,heap->pos);
        heap->pos++;
    } else {
        printf("Heap CHEIO!\n"); 
    }
}

void corrige_abaixo(int *prios, int atual, int tam) {
    int pai = atual;
    int filho_esq, filho_dir, filho;
    while (2*pai+1 < tam){
        filho_esq = 2*pai+1;
        filho_dir = 2*pai+2;
        if (filho_dir < tam && prios[filho_esq] < prios[filho_dir]) {
            filho = filho_dir;
        } else {
            filho = filho_esq;
        }
        if (prios[pai] < prios[filho]) {
            troca(pai,filho,prios);
        } else {
            break;
        }
        pai = filho;
    }
}

int heap_remove(struct Heap* heap) {
    if (heap->pos > 0) {
        int topo = heap->prioridade[0];
        heap->prioridade[0] = heap->prioridade[heap->pos-1];
        heap->pos--;
        corrige_abaixo(heap->prioridade, 0, heap->pos);
        return topo;
    }
    printf("Heap VAZIO!");
    return -1;
}

void heap_imprime(struct Heap* heap) {
    printf("Heap: ");
    for (int i = 0; i < heap->pos; i++) {
        printf("%d ", heap->prioridade[i]);
    }
    printf("\n");
}

int ehVazia(struct Heap* heap) {
    return heap->pos == 0;
}

int ehCheia(struct Heap* heap) {
    return heap->pos == heap->max;
}

int main() { 
    struct Heap* heap = heap_inicializa(TAM);
    int v[TAM] = {11, 2, 3, 8, 1, 4, 6, 9, 5, 7};

    printf("Vetor antes da ordenacao:\n");
    for (int i = 0; i < TAM; i++){
        printf("%d ", v[i]);
    }

    for (int i = 0; i < TAM; i++){
        heap_insere(heap, v[i]);
    }
    for (int j = TAM-1; j >= 0; j--){
        v[j] = heap_remove(heap);
    }
    
    printf("\nVetor apos a ordenacao:\n");
    for (int i = 0; i < TAM; i++){
        printf("%d ", v[i]);
    } 

    // Libera memória
    free(heap->prioridade);
    free(heap);

    return 0;
}
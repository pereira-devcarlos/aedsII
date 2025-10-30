#include <stdio.h> 
#include <stdlib.h>
#include "ordenacao.h"
  
// Imprime um vetor de inteiros
void imprimir(int *vetor) {
    int i;
    for (i = 0; i < 50; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void bubble(int *vetor) {
    // loop externo controla o número de passagens
    for (int i = 50; i >= 0; i--){
        // loop interno realiza as comparações e trocas
        for (int j = 0; j < 50-1; j++){
            // Verifica se o elemento atual é maior que o próximo
            if (vetor[j] > vetor[j+1]){
                // Troca os elementos de posição
                int aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }

    imprimir(vetor);
    return;
}

void selection(int *vetor) {
    // loop externo percorre todo o vetor
    for (int i = 0; i < 50 -1; i++){
        int menorInd = i; // índice do menor elemento encontrado
        for (int j = i; j < 50; j++){
            // Compara o elemento atual com o menor encontrado
            if (vetor[menorInd] > vetor[j]){
                // Atualiza o índice do menor elemento
                menorInd = j;
            }
        }
        // Troca o menor elemento encontrado com o elemento na posição i
        if (menorInd != i){
            int aux = vetor[i];
            vetor[i] = vetor[menorInd];
            vetor[menorInd] = aux;
        }
    }
    
    imprimir(vetor);
    return;
}

void insertion(int *vetor) {
    // loop externo percorre todo o vetor
    for (int i = 1; i < 50; i++){
        int chave = vetor[i]; // elemento a ser inserido na posição correta
        int j = i -1;         // índice do elemento anterior

        // Move os elementos maiores que a chave para a direita
        while (j >= 0 && vetor[j] > chave){
            vetor[j+1] = vetor[j];
            j--;
        }
        // Insere a chave na posição correta
        vetor[j+1] = chave;
    }
    
    imprimir(vetor);
    return;
}

void merge(int *vetor, int inicio, int meio, int fim) {
    // Cria os vetores temporários
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    // Aloca memória para os vetores temporários
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copia os dados para os vetores temporários L[] e R[]
    for (int i = 0; i < n1; i++){
        L[i] = vetor[inicio + i];
    } 
    for (int j = 0; j < n2; j++){
        R[j] = vetor[meio + 1 + j];
    } 

    // Índices iniciais dos vetores temporários e do vetor principal
    int i = 0, j = 0, k = inicio;

    // Intercala enquanto houver elementos em ambos os lados
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vetor[k++] = L[i++];
        } else {
            vetor[k++] = R[j++];
        }
    }

    // Copia o restante (se houver)
    while (i < n1) vetor[k++] = L[i++];
    while (j < n2) vetor[k++] = R[j++];

    // Libera a memória alocada
    free(L);
    free(R);
}

void mergeSort(int *vetor,int inicio,int fim){
    // Verifica se o vetor pode ser dividido
    if (inicio < fim){
        // Encontra o ponto médio
        int meio = (inicio + fim)/2;

        // Chama recursivamente para as duas metades
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio+1, fim);

        // Intercala as duas metades ordenadas
        merge(vetor, inicio, meio, fim);
    }
}

// Função de particionamento para o QuickSort
int particiona(int V[], int inicio, int final) {
    int esq = inicio;
    int dir = final;
    int pivo = V[inicio];
    int aux;

    while (esq < dir) {
        // Avança posição da esquerda enquanto os elementos forem <= pivo
        while (esq <= final && V[esq] <= pivo)
            esq++;

        // Recuar posição da direita enquanto os elementos forem > pivo
        while (dir >= 0 && V[dir] > pivo)
            dir--;

        // Se ainda não se cruzaram, troca os elementos
        if (esq < dir) {
            aux = V[esq];
            V[esq] = V[dir];
            V[dir] = aux;
        }
    }

    // Coloca o pivô na posição correta
    V[inicio] = V[dir];
    V[dir] = pivo;

    // Retorna a posição final do pivô
    return dir;
}

// Função recursiva QuickSort
void quickSort(int V[], int inicio, int final) {
    int posPivo;

    if (inicio < final) { // Condição de parada
        posPivo = particiona(V, inicio, final); // Divide o vetor
        quickSort(V, inicio, posPivo - 1);      // Ordena a parte esquerda
        quickSort(V, posPivo + 1, final);       // Ordena a parte direita
    }
}

int main() { 
  // Vetor aleatório de 50 posições
  
  int n;
  do {
    int vetor[50] = {40, 32, 24, 25,  1, 48, 38,  7, 17,  8, 42,  4, 44, 45, 27, 49, 30, 18,  6, 23,  5, 41, 33, 26, 28,  3, 37, 19, 11, 43, 39, 16, 36, 21,  9,  2, 47, 12, 50, 20, 14, 29, 35, 46, 13, 34, 31, 15, 10, 2};
    printf("\n\n******************** Escolha seu algoritmo *******************");
    printf("\n1.Bubble sort");
    printf("\n2.Selection sort");
    printf("\n3.Insertion sort");
    printf("\n4.Merge sort");
    printf("\n5.Quick sort");
    printf("\n0.Sair");
    printf("\nEntre sua opção : ");
    scanf("%d",&n);
    switch(n) {
        case 1: 
            bubble(vetor);
            break;
        case 2: 
            selection(vetor);
            break;
        case 3: 
            insertion(vetor);
            break;
        case 4: 
            mergeSort(vetor, 0, 49);
            imprimir(vetor);
            break;
        case 5: 
            quickSort(vetor, 0, 49);
            imprimir(vetor); // imprime só o resultado final
            break;
        case 0: 
            exit(0);
            break;
        default: 
            printf("\n Opção errada!");
            break;
    }
  } while(1);

  return 0; 
}
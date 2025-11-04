#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenacao.h"

// Função auxiliar para encontrar o valor máximo no array.
// Isso é necessário para o Counting Sort (para saber o tamanho 'k')
// e para o Radix Sort (para saber o número de dígitos)
int getMax(int arr[], int n) {
    if (n <= 0) return 0;
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Função auxiliar para imprimir um array
void printArray(const char* algorithmName, int arr[], int n) {
    printf("%s: \n[ ", algorithmName);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n\n");
}

// Função auxiliar para copiar um array (para testar os 3 algos no mesmo conjunto)
void copyArray(int* dest, int* src, int n) {
    for(int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}


/*
 * ============================================================================
 * 1. COUNTING SORT 
 * ============================================================================
 */
void countingSort(int arr[], int n) {
    if (n <= 0) return;

    // Encontrar o valor máximo 'k' para determinar o tamanho do vetor de contagem
    int k = getMax(arr, n); 

    // Alocar vetor de contagem C de tamanho k+1 e inicializar com zeros 
    // (Usamos k+1 para lidar com o índice 0)
    int* count = (int*)malloc((k + 1) * sizeof(int));
    if (count == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }
    // Inicializa o vetor de contagem com zeros 
    memset(count, 0, (k + 1) * sizeof(int));

    // Contar a ocorrência de cada elemento em A e salvar em C
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Reconstruir o vetor A de forma ordenada iterando sobre C 
    int j = 0; // Índice para o array 'arr'
    for (int i = 0; i <= k; i++) {
        while (count[i] > 0) {
            arr[j] = i;
            j++;
            count[i]--;
        }
    }

    // 5. Liberar memória
    free(count);
}


/*
 * ============================================================================
 * 2. BUCKET SORT 
 * ============================================================================
 */

// Função para inserir um nó na lista de forma ordenada (Insertion Sort)
// O slide sugere ordenar cada bucket, e o Insertion Sort é uma boa escolha
struct Node* insertionSortList(struct Node* list_head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) exit(1); // Falha na alocação
    newNode->data = value;
    newNode->next = NULL;

    if (list_head == NULL || list_head->data >= value) {
        newNode->next = list_head;
        return newNode;
    }

    struct Node* current = list_head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return list_head;
}

/**
 * Implementação do Bucket Sort.
 * Agrupa elementos de valor similar em "buckets"
 */
void bucketSort(int arr[], int n) {
    if (n <= 0) return;

    // Criar 'n' buckets
    // Usaremos 'n' buckets, uma escolha comum.
    struct Node** buckets = (struct Node**)malloc(n * sizeof(struct Node*));
    if (buckets == NULL) exit(1);

    // Inicializa todos os buckets como vazios (NULL)
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    // Encontrar o valor máximo 'k' para normalizar os índices
    int k = getMax(arr, n);

    // Distribuir os elementos de A nos buckets 
    for (int i = 0; i < n; i++) {
        // Fórmula de hash para distribuir uniformemente
        int bucketIndex = (int)(n * (double)arr[i] / (k + 1));
        
        // Insere o elemento no bucket de forma ordenada
        // Podemos otimizar inserindo e ordenando de uma vez.
        buckets[bucketIndex] = insertionSortList(buckets[bucketIndex], arr[i]);
    }

    // (Este passo foi combinado com o 3, ao usar insertionSortList)
    // Se não fosse combinado, aqui iteraríamos cada bucket e o ordenaríamos
    
    // Concatenar os buckets de volta no array original A
    int index = 0;
    for (int i = 0; i < n; i++) {
        struct Node* current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->data;
            
            // Libera a memória da lista
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    // Libera a memória do array de buckets
    free(buckets);
}


/*
 * ============================================================================
 * 3. RADIX SORT 
 * ============================================================================
 */
void countingSortForRadix(int arr[], int n, int exp) {
    int* output = (int*)malloc(n * sizeof(int));
    if (output == NULL) exit(1);
    
    int count[10] = {0}; // k = 10

    // Contar ocorrências do dígito (arr[i] / exp) % 10
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Mudar count[i] para que contenha a posição do dígito no output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Construir o array de saída (iterando de trás para frente para estabilidade)
    for (int i = n - 1; i >= 0; i--) {
        int digitIndex = (arr[i] / exp) % 10;
        output[count[digitIndex] - 1] = arr[i];
        count[digitIndex]--;
    }

    // Copiar o array de saída para arr[]
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(output);
}

/**
 * Implementação do Radix Sort (LSD - Least Significant Digit)
 * Ordena dígito por dígito, do menos significativo para o mais significativo
 */
void radixSort(int arr[], int n) {
    if (n <= 0) return;

    // Encontrar o valor máximo para saber o número de dígitos
    int max = getMax(arr, n);

    // Fazer o Counting Sort para cada dígito
    // O 'exp' é 1, 10, 100...
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSortForRadix(arr, n, exp);
    }
}

int main() {
    printf("Atividade Pratica - Algoritmos de Ordenacao Linear\n");
    printf("Implementacao baseada em aula_24 (1).pdf\n\n");
    
    // Vetor de exemplo do Bucket Sort (Slide 12)
    int A[] = {61, 42, 67, 27, 17, 75, 56, 93, 76, 46, 63, 55, 70, 59, 98, 9, 7, 67, 95, 90};
    int n = sizeof(A) / sizeof(A[0]);

    // Criar cópias do array para cada algoritmo
    int A_counting[n];
    int A_bucket[n];
    int A_radix[n];

    copyArray(A_counting, A, n);
    copyArray(A_bucket, A, n);
    copyArray(A_radix, A, n);

    // 1. Testar Counting Sort
    printArray("Array Original", A_counting, n);
    countingSort(A_counting, n);
    printArray("1. Counting Sort", A_counting, n);

    // 2. Testar Bucket Sort
    printArray("Array Original", A_bucket, n);
    bucketSort(A_bucket, n);
    printArray("2. Bucket Sort", A_bucket, n);

    // 3. Testar Radix Sort
    printArray("Array Original", A_radix, n);
    radixSort(A_radix, n);
    printArray("3. Radix Sort", A_radix, n);

    return 0;
}
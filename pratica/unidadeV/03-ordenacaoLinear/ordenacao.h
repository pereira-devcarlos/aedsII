#ifndef _H_ORDENACAO_
#define _H_ORDENACAO_

// Estrutura para a lista linear
struct Node {
    int data;
    struct Node* next;
};

int getMax(int arr[], int n);
void printArray(const char* algorithmName, int arr[], int n);
void copyArray(int* dest, int* src, int n);
void countingSort(int arr[], int n);
struct Node* insertionSortList(struct Node* list_head, int value);
void bucketSort(int arr[], int n);
void countingSortForRadix(int arr[], int n, int exp);
void radixSort(int arr[], int n);


#endif // _H_ORDENACAO_
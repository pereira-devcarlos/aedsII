#ifndef _H_ORDENACAO_
#define _H_ORDENACAO_

void imprimir(int *vetor);
void bubble(int *vetor);
void selection(int *vetor);
void insertion(int *vetor);
void merge(int *vetor, int inicio, int meio, int fim);
void mergeSort(int *vetor,int inicio,int fim);
int particiona(int V[], int inicio, int final);
void quickSort(int V[], int inicio, int final);

#endif // _H_ORDENACAO_
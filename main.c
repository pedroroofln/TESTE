#include <stdio.h>
  
  void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  
  void heapify(int vet[], int n, int i) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;
  
    if (esq < n && vet[esq] > vet[maior])
      maior = esq;
  
    if (dir < n && vet[dir] > vet[maior])
      maior = dir;
  
    if (maior != i) {
      swap(&vet[i], &vet[maior]);
      heapify(vet, n, maior);
    }
  }
  void heapSort(int vet[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(vet, n, i);
  
    for (int i = n - 1; i >= 0; i--) {
      swap(&vet[0], &vet[i]);
  
      heapify(vet, i, 0);
    }
  }
  
  void printvetay(int vet[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%d ", vet[i]);
    printf("\n");
  }
  
  int main() {
    int vet[] = {67, 21, 3, 40, 76, 30};
    int n = sizeof(vet) / sizeof(vet[0]);
  
    heapSort(vet, n);
  
    printf("O vetor em ordem crescente: \n");
    printvetay(vet, n);
  }
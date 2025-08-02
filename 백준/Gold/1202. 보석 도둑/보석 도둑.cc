#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *data;
  int size;
} MaxHeap;

MaxHeap *createMaxHeap(const int capacity) {
  MaxHeap *heap = (MaxHeap *)malloc(sizeof(MaxHeap));
  heap->data = (int *)malloc(sizeof(int) * (capacity+1));
  heap->size = 0;
  return heap;
}

void swap(int *a, int *b) {
  const int temp = *a;
  *a = *b;
  *b = temp;
}

void push(MaxHeap *heap, int value) {
  int i = ++(heap->size);
  heap->data[i] = value;
  while (i > 1 && heap->data[i] > heap->data[i/2]) {
    swap(&heap->data[i], &heap->data[i/2]);
    i /= 2;
  }
}

int pop(MaxHeap *heap) {
  if (heap->size == 0) return 0;
  int top = heap->data[1];
  heap->data[1] = heap->data[heap->size--];
  int i = 1;
  while (1) {
    int left = i*2, right = i*2+1, max = i;
    if (left <= heap->size && heap->data[left] > heap->data[max]) max = left;
    if (right <= heap->size && heap->data[right] > heap->data[max]) max = right;
    if (max == i) break;
    swap(&heap->data[i], &heap->data[max]);
    i = max;
  }
  return top;
}

typedef struct {
  int price;
  int weight;
} Jewel;

int compareJ(const void* a, const void* b) {
  return ((Jewel*)a)->weight - ((Jewel*)b)->weight;
}

int compare(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  Jewel *jewel = (Jewel*)malloc(sizeof(Jewel) * n);
  int *bag = (int*)malloc(k * sizeof(int));
  for (int i = 0; i < n; i++) scanf("%d %d", &jewel[i].weight, &jewel[i].price);
  for (int i = 0; i < k; i++) scanf("%d", &bag[i]);
  qsort(bag, k, sizeof(int), compare);
  qsort(jewel, n, sizeof(Jewel), compareJ);

  MaxHeap *heap = createMaxHeap(n);
  long long result = 0;

  int j = 0;
  for (int i = 0; i < k; i++) {
    while (j < n && jewel[j].weight <= bag[i]) {
      push(heap, jewel[j].price);
      j++;
    }

    if (heap->size > 0) result += pop(heap);
  }

  printf("%lld\n", result);

  free(jewel);
  free(bag);
  free(heap);
  return 0;
}
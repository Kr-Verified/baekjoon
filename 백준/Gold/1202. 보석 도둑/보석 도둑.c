#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *data;
  int size;
} MaxHeap;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

MaxHeap* createMaxHeap(int capacity) {
  MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
  heap->data = (int*)malloc(sizeof(int) * (capacity+1));
  heap->size = 0;
  return heap;
}

void heappush(MaxHeap *heap, int value) {
  heap->data[++(heap->size)] = value;
  int i = heap->size;
  while (i > 1 && heap->data[i] > heap->data[i/2]) {
    swap(&heap->data[i], &heap->data[i/2]);
    i /= 2;
  }
}

int heappop(MaxHeap *heap) {
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

int compareJ(const void *a, const void *b) {
  return ((Jewel*)a)->weight - ((Jewel*)b)->weight;
}

int compare(const void *a, const void *b) {
  return *(int*)a - *(int*)b;
}

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  Jewel *jewel = (Jewel*)malloc(sizeof(Jewel) * n);
  for (int i = 0; i < n; i++) scanf("%d %d", &jewel[i].weight, &jewel[i].price);
  int *bag = (int*)malloc(sizeof(int) * k);
  for (int i = 0; i < k; i++) scanf("%d", &bag[i]);

  MaxHeap *heap = createMaxHeap(n);

  qsort(bag, k, sizeof(int), compare);
  qsort(jewel, n, sizeof(Jewel), compareJ);

  long long int result = 0;
  int j = 0;
  for (int i = 0; i < k; i++) {
    while (j < n && jewel[j].weight <= bag[i]) {
      heappush(heap, jewel[j].price);
      j++;
    }
    result += heappop(heap);
  }

  printf("%lld\n", result);
  
  free(bag);
  free(jewel);
  free(heap);
  return 0;
}
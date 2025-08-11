#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *data;
  int size;
} MinHeap;

MinHeap* createMinHeap(const int capacity) {
  MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
  heap->data = (int*)malloc(sizeof(int)*(capacity+1));
  heap->size = 0;
  return heap;
}

void swap(int* a, int* b) {
  const int temp = *a;
  *a = *b;
  *b = temp;
}

void push(MinHeap* heap, const int val) {
  int i = ++heap->size;
  heap->data[i] = val;
  while (i>1 && heap->data[i] < heap->data[i/2]) {
    swap(&heap->data[i], &heap->data[i/2]);
    i /= 2;
  }
}

int pop(MinHeap* heap) {
  if (heap->size == 0) return 0;
  int top = heap->data[1];
  heap->data[1] = heap->data[heap->size--];
  int i = 1;
  while (1) {
    int left = i*2, right = i*2+1, min = i;
    if (left <= heap->size && heap->data[left] < heap->data[min]) min = left;
    if (right <= heap->size && heap->data[right] < heap->data[min]) min = right;
    if (min == i) break;
    swap(&heap->data[min], &heap->data[i]);
    i = min;
  }
  return top;
}

int get_len(MinHeap* heap) {
  if (heap->size == 0) return 0;
  return heap->size;
}


int main(void) {
  int n, m, edges[100000][2], indegrees[32001]={0};
  scanf("%d %d",&n,&m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d",&edges[i][0],&edges[i][1]);
    indegrees[edges[i][1]]++;
    }

  MinHeap* queue = createMinHeap(n);
  for (int i = 1; i <= n; i++) {
    if (indegrees[i] == 0) push(queue, i);
  }

  int result[32000], len=0;
  while (get_len(queue)!=0) {
    int vertex = pop(queue);
    result[len++] = vertex;

    for (int i = 0; i < m; i++) {
      if (edges[i][0] == vertex) {
        if (--indegrees[edges[i][1]] == 0) push(queue, edges[i][1]);
      }
    }
  }

  for (int i = 0; i < len; i++) printf("%d ",result[i]);

  free(queue);
  return 0;
}
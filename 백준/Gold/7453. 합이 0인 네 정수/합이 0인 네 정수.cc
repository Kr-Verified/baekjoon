#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
  return *(int*)a - *(int*)b;
}

int lower_bound(int *arr, int size, int x) {
  int left = 0, right = size;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] < x) left = mid + 1;
    else right = mid;
  }
  return left;
}

int upper_bound(int *arr, int size, int x) {
  int left = 0, right = size;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] <= x) left = mid + 1;
    else right = mid;
  }
  return left;
}

int main() {
  int n;
  scanf("%d", &n);
  int *A = (int*)malloc(n*sizeof(int));
  int *B = (int*)malloc(n*sizeof(int));
  int *C = (int*)malloc(n*sizeof(int));
  int *D = (int*)malloc(n*sizeof(int));
  int *AB = (int*)malloc(n*n*sizeof(int));
  int *CD = (int*)malloc(n*n*sizeof(int));

  for (int i = 0; i < n; i++) scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) AB[i*n+j] = A[i] + B[j];
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) CD[i*n+j] = C[i] + D[j];

  qsort(CD, n*n, sizeof(int), compare);

  long long int cnt = 0;
  for (int i = 0; i < n*n; i++) {
    int left = lower_bound(CD, n*n, -AB[i]);
    int right = upper_bound(CD, n*n, -AB[i]);
    cnt += right - left;
  }
  printf("%lld\n", cnt);

  free(A);
  free(B);
  free(C);
  free(D);
  free(AB);
  free(CD);
  return 0;
}
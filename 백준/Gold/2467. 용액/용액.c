#include <stdio.h>
#include <stdlib.h>

void merge(int*arr, int left, int mid, int right) {
  int len1 = mid - left + 1;
  int len2 = right - mid;
  int* g1 = (int*)malloc(sizeof(int) * (len1));
  int* g2 = (int*)malloc(sizeof(int) * (len2));
  for (int i = 0; i < len1; i++) g1[i] = arr[left + i];
  for (int i = 0; i < len2; i++) g2[i] = arr[mid + i + 1];

  int i = 0, j = 0, k = left;
  while (i < len1 && j < len2) {
    if (g1[i] < g2[j]) arr[k++] = g1[i++];
    else arr[k++] = g2[j++];
  }

  while (i < len1) arr[k++] = g1[i++];
  while (j < len2) arr[k++] = g2[j++];

  free(g1);
  free(g2);
}

void merge_sort(int*arr, int left, int right) {
  if (left < right) {
    const int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}

int abs(int value) {
  return value > 0 ? value : -value;
}

int main(void) {
  int n, min_value = 2000000000, x, y;
  scanf("%d",&n);
  int* arr = (int*)malloc(n*sizeof(int));
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  merge_sort(arr, 0, n - 1);

  int left = 0, right = n - 1;
  while (left < right) {
    const int value = arr[left] + arr[right];
    if (min_value > abs(value)) {
      min_value = abs(value);
      x = left;
      y = right;
    }else {
      if (value > 0) right--;
      else left++;
    }
  }

  printf("%d %d\n", arr[x], arr[y]);

  return 0;
}
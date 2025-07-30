#include <stdio.h>
#include <stdlib.h>

int a_sub[500501], b_sub[500501];

int compare(const void *a, const void *b) {
  return (*(int*)a - *(int*)b);
}

int binary_search_left(const int arr[], const int size, const int x) {
  int left = 0, right = size;
  while (left < right) {
    int mid = (left + right) / 2;
    if (arr[mid] < x) left = mid + 1;
    else right = mid;
  }
  return left;
}

int binary_search_right(const int arr[], const int size, const int x) {
  int left = 0, right = size;
  while (left < right) {
    int mid = (left + right) / 2;
    if (arr[mid] <= x) left = mid + 1;
    else right = mid;
  }
  return left;
}

int main(void) {
  int T, al, bl, a[1000], b[1000];
  scanf("%d", &T);
  scanf("%d", &al);
  for (int i = 0; i < al; i++) scanf("%d", &a[i]);
  scanf("%d", &bl);
  for (int i = 0; i < bl; i++) scanf("%d", &b[i]);

  int a_cnt = 0, b_cnt = 0;
  for (int i = 0; i < al; i++) {
    int sum = 0;
    for (int j = i; j < al; j++) {
      sum += a[j];
      a_sub[a_cnt++] = sum;
    }
  }
  for (int i = 0; i < bl; i++) {
    int sum = 0;
    for (int j = i; j < bl; j++) {
      sum += b[j];
      b_sub[b_cnt++] = sum;
    }
  }
  qsort(b_sub, b_cnt, sizeof(int), compare);

  long long result = 0;
  for (int i = 0; i < a_cnt; i++) {
    int x = T - a_sub[i];
    int left = binary_search_left(b_sub, b_cnt, x);
    int right = binary_search_right(b_sub, b_cnt, x);
    result += right-left;
  }

  printf("%lld\n", result);
  return 0;
}
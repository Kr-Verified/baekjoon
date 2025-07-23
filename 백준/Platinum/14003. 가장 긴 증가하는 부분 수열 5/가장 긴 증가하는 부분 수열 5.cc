#include <stdio.h>
#include <stdlib.h>

int binary_search_left(int* tail, int n, int key) {
  int left = 0, right = n;
  while (left < right) {
    int mid = (left + right) / 2;
    if (tail[mid] < key) left = mid + 1;
    else right = mid;
  }
  return left;
}

int main(void) {
  int n;
  scanf("%d", &n);
  int* nums = (int*)malloc(sizeof(int)*n);
  int* tail = (int*)malloc(sizeof(int)*n);
  int* tail_idx = (int*)malloc(sizeof(int)*n);
  int* parents = (int*)malloc(sizeof(int)*n);
  int length = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &nums[i]);
    tail[i] = 0;
    tail_idx[i] = 0;
    parents[i] = -1;
  }

  for (int i = 0; i < n; i++) {
    int key = nums[i];
    int idx = binary_search_left(tail, length, key);
    if (idx == length)
    {
      tail[length] = key;
      tail_idx[length++] = i;
    }
    else {
      tail[idx] = key;
      tail_idx[idx] = i;
    }
    if (idx > 0) parents[i] = tail_idx[idx-1];
  }

  printf("%d\n", length);
  int cur = tail_idx[length-1];
  int *temp = (int*)malloc(sizeof(int)*length);
  for (int i = length-1; i >= 0; i--) {
    temp[i] = nums[cur];
    cur = parents[cur];
  }

  for (int i = 0; i < length; i++) printf("%d ", temp[i]);

  free(temp);
  free(nums);
  free(tail);
  free(tail_idx);
  free(parents);
  return 0;
}
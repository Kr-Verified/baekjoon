#include <stdio.h>
#include <stdlib.h>
#define MAX 3000000001LL

int compare(const void *a, const void *b) {
  return (*(int*)a - *(int*)b);
}

int main(void) {
  int n;
  scanf("%d", &n);

  long long* nums = (long long*)malloc(n*sizeof(long long));
  for (int i = 0; i < n; i++) scanf("%lld", &nums[i]);
  qsort(nums, n, sizeof(long long), compare);
  long long min = MAX;
  int idx[3];
  for (int i = 0; i < n-2; i++) {
    int left = i+1, right = n-1;
    while (left < right) {
      long long temp = nums[left]+nums[right]+nums[i];
      long long abs = temp > 0 ? temp : -temp;
      if (min > abs) {
        min = abs;
        idx[0] = nums[i];
        idx[1] = nums[left];
        idx[2] = nums[right];
      }
      if (temp > 0) right -= 1;
      else left += 1;
    }
  }
  printf("%d %d %d\n", idx[0], idx[1], idx[2]);
  free(nums);
  return 0;
}
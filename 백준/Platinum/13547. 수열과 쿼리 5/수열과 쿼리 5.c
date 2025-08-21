#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int block_size;
int nums_c[1000001] = {0};

typedef struct {
  int idx, left, right;
} Query;

int compare(const void *q1, const void *q2) {
  Query *a = (Query*)q1;
  Query *b = (Query*)q2;

  if (a->left/block_size != b->left/block_size) return a->left/block_size - b->left/block_size;
  return a->right - b->right;
}

int main(void) {
  int n, q;
  scanf("%d", &n);
  int *nums = (int*)malloc(sizeof(int) * n);
  block_size = sqrt(n);
  for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

  scanf("%d", &q);
  Query *qs = (Query*)malloc(sizeof(Query) * q);
  for (int i = 0; i < q; i++) {
    scanf("%d %d", &qs[i].left, &qs[i].right);
    qs[i].idx = i;
    qs[i].left--;
    qs[i].right--;
  }
  qsort(qs, q, sizeof(Query), compare);

  int *answer = (int*)malloc(sizeof(int) * q);
  int ml = 0, mr = -1, cnt = 0;
  for (int i = 0; i < q; i++) {
    int l = qs[i].left, r = qs[i].right;

    while (ml > l) {
      if (nums_c[nums[--ml]] == 0) cnt++;
      nums_c[nums[ml]]++;
    }
    while (mr < r) {
      if (nums_c[nums[++mr]] == 0) cnt++;
      nums_c[nums[mr]]++;
    }
    while (ml < l) {
      if (nums_c[nums[ml]] == 1) cnt--;
      nums_c[nums[ml++]]--;
    }
    while (mr > r) {
      if (nums_c[nums[mr]] == 1) cnt--;
      nums_c[nums[mr--]]--;
    }

    answer[qs[i].idx] = cnt;
  }

  for (int i = 0; i < q; i++) printf("%d\n", answer[i]);

  return 0;
}
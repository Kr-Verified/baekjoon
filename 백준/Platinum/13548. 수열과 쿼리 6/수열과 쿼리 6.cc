#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int block_size;
int nums_c[100001] = {0};

typedef struct{
    int idx, left, right;
} Query;

int compare(const void *q1, const void *q2) {
    Query *a = (Query *)q1;
    Query *b = (Query *)q2;
    if (a->left/block_size != b->left/block_size) return a->left/block_size - b->left/block_size;
    return a->right - b->right;
}

int main(void) {
    int n, q;
    scanf("%d", &n);
    int* nums = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    scanf("%d", &q);
    Query* qs = (Query*)malloc(sizeof(Query) * q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &qs[i].left, &qs[i].right);
        qs[i].idx = i;
        qs[i].left--;
        qs[i].right--;
    }
    block_size = sqrt(n);
    qsort(qs, q, sizeof(Query), compare);

    int* answer = (int*)malloc(sizeof(int) * q);
    int ml=0, mr=-1, max=0, count[100001] = {0};
    for (int i = 0; i < q; i++) {
        int l = qs[i].left, r = qs[i].right;

        while (ml > l) {
            int val = nums[--ml];
            if (nums_c[val] > 0) count[nums_c[val]]--;
            nums_c[val]++;
            count[nums_c[val]]++;
            if (max < nums_c[val]) max = nums_c[val];
        }
        while (mr < r) {
            int val = nums[++mr];
            count[nums_c[val]]--;
            nums_c[val]++;
            count[nums_c[val]]++;
            if (max < nums_c[val]) max = nums_c[val];
        }
        while (ml < l) {
            int val = nums[ml];
            count[nums_c[val]]--;
            nums_c[val]--;
            count[nums_c[val]]++;
            while (max > 0 && count[max] == 0) max--;
            ml++;
        }
        while (mr > r) {
            int val = nums[mr];
            count[nums_c[val]]--;
            nums_c[val]--;
            count[nums_c[val]]++;
            while (max > 0 && count[max] == 0) max--;
            mr--;
        }

        answer[qs[i].idx] = max;
    }

    for (int i = 0; i < q; i++) printf("%d\n", answer[i]);
    return 0;
}
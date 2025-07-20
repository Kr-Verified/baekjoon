#include <stdio.h>

int main(void) {
    int n, max=0;
    int nums[1001];
    float sum = 0;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &nums[i]);
        if (max < nums[i]) max = nums[i];
    }
    for (int i=0; i<n; i++) sum += (float)nums[i]/max*100;
    printf("%f", sum/n);
    return 0;
}
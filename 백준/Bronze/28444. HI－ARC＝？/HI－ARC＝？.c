#include <stdio.h>

int main(void) {
    int hi[2], arc[3];
    scanf("%d %d", &hi[0], &hi[1]);
    scanf("%d %d %d", &arc[0], &arc[1], &arc[2]);
    printf("%d", (hi[0]*hi[1])-(arc[0]*arc[1]*arc[2]));
    return 0;
}
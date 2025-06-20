#include <stdio.h>

int main(void) {
    int a, b, c;
    scanf("%d", &a);
    scanf("%d %d", &b, &c);
    printf("%d", (b/c)>=a);
    return 0;
}
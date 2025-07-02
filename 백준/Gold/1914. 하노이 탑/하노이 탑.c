#include <stdio.h>

void hanoi(int n, int from, int to, int aux) {
    if (n==1) {
      printf("%d %d\n", from, to);
      return;
    }
    hanoi(n-1, from, aux, to);
    printf("%d %d\n", from, to);
    hanoi(n-1, aux, to, from);
}

int main(void) {
    int n, result[101]={0}, len=0, carry=0;
    result[0] = 1;
    scanf("%d", &n);
    for (int i=0; i<n; i++) for (int j=0; j<100; j++) {
      result[j]*=2;
      if (carry) {
        result[j]++;
        carry=0;
      }
      if (result[j]>9) {
        result[j]%=10;
        carry=1;
      }
      if (result[j]!=0 && j>len) len=j;
    }
    for (int i=len; i>0; i--) printf("%d", result[i]);
    printf("%d\n", result[0]-1);
    if (n<=20) hanoi(n, 1, 3, 2);
    return 0;
}
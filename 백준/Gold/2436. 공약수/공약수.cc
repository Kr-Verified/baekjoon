#include <stdio.h>
#include <math.h>

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

int main(void) {
  int g, l;
  scanf("%d %d", &g, &l);

  int temp = l/g;
  int result = 0;
  for (int i = (int)sqrt(temp); i>=0; i--) {
    if (temp%i == 0) {
      result = temp/i;
      if (gcd(result, i) == 1) break;
    }
  }
  printf("%d %d\n", temp/result*g, result*g);

  return 0;
}

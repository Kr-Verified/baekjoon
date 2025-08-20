#include <stdio.h>
#include <math.h>

int gcd(int a, int b) {
  while (b != 0) {
    int temp = a;
    a = b;
    b = temp % a;
  }
  return a;
}

int main(void) {
  int g, l;
  scanf("%d %d", &g, &l);

  int mul = l/g;
  for (int i = (int)sqrt(mul); i > 0; i--) {
    if (mul % i == 0 && gcd(i, mul/i) == 1) {
      printf("%d %d\n", i*g, mul/i*g);
      break;
    }
  }

  return 0;
}
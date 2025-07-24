#include <stdio.h>
#include <math.h>

int main(void) {
  int k, cnt[1000001] = {0}, i=2;
  scanf("%d", &k);

  int temp = k, total = 0;
  while (temp > 0 && temp >= i) {
    while (temp%i == 0) {
      cnt[i]++;
      total++;
      temp/=i;
    }
    i++;
  }

  int result = (int)ceil(log2(total));
  printf("%d", result);
  return 0;
}
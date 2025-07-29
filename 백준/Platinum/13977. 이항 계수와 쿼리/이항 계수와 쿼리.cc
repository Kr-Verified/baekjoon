#include <stdio.h>
#define MAX 4000000
#define MOD 1000000007

long long fac[MAX+1], inv_fac[MAX+1];

long long powmod(long long a, int b) {
  long long res = 1;
  a %= MOD;
  while (b > 0) {
    if (b % 2) res = res * a % MOD;
    a = a * a % MOD;
    b /= 2;
  }
  return res;
}

int main(void) {
  fac[0] = 1;
  for (int i = 1; i <= MAX; i++) fac[i] = fac[i-1] * i % MOD;
  inv_fac[MAX] = powmod(fac[MAX], MOD - 2);
  for (int i = MAX-1; i >= 0; i--) inv_fac[i] = inv_fac[i+1] * (i+1) % MOD;
  int n, a, b;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &a, &b);
    printf("%d\n", fac[a] * inv_fac[b] % MOD * inv_fac[a-b] % MOD);
  }
  return 0;
}
#include <stdio.h>
#define ull unsigned long long

int prime_list[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};

void swap(ull* a, ull* b) {
  ull t = *a;
  *a = *b;
  *b = t;
}

ull abs_(ull a, ull b) {
  if (a > b) return a - b;
  return b - a;
}

ull pow_(ull a, ull b, ull n) {
  __uint128_t result = 1;
  __uint128_t base = a%n;
  while (b > 0) {
    if (b & 1) result = (result * base) % n;
    base = (base * base) % n;
    b >>= 1;
  }
  return (ull)result;
}

ull gcd(ull a, ull b) {
  if (a < b) swap(&a, &b);
  while (b != 0) {
    ull t = b;
    b = a % b;
    a = t;
  }
  return a;
}

int miller_rabin(ull n) {
  int s = 0;
  ull d = n - 1;
  while (d % 2 == 0) {
    d /= 2;
    s++;
  }

  int a_list[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
  for (int a_i = 0; a_i < 12; a_i++) {
    ull a = a_list[a_i];
    ull x = a;
    x = pow_(x, d, n);
    if (x == 1 || x == n - 1) continue;
    int flag = 0;
    for (int i = 0; i < s - 1; i++) {
      x = pow_(x, 2, n);
      if (x == n - 1) {
        flag = 1;
        break;
      }
    }
    if (!flag) return 0;
  }
  return 1;
}

int is_prime(ull n) {
  if (n <= 71) {
    for (int i = 0; i < 20; i++) if (prime_list[i] == n) return 1;
    return 0;
  }
  return miller_rabin(n);
}

ull g(ull x, ull n) {
  __uint128_t temp = (__uint128_t)x;
  return (ull)((temp * temp + 1) % n);
}

ull pollard_rho(ull n, ull x) {
  if (is_prime(n)) return n;
  for (int i = 0; i < 20; i++) if (n % prime_list[i] == 0) return prime_list[i];

  ull temp = x, y = x, d = 1;
  while (1) {
    while (d == 1) {
      x = g(x, n);
      y = g(g(y, n), n);
      d = gcd(abs_(x, y), n);
    }
    if (d == n) {
      temp++;
      x = temp;
      y = temp;
      d = 1;
    }else {
      if (miller_rabin(d)) return d;
      return pollard_rho(d, 2);
    }
  }
}

int main(void) {
  ull n, k, answer[100000];
  int len = 0;
  scanf("%llu", &n);

  k = n;
  while (k != 1) {
    const ull prime = pollard_rho(k, 2);
    k /= prime;
    int flag = 0;
    for (int i = 0; i < len; i++) {
      if (answer[i] == prime) {
        flag = 1;
        break;
      }
    }
    if (!flag) answer[len++] = prime;
  }

  for (int i = 0; i < len; i++) {
    n = n / answer[i] * (answer[i] - 1);
  }

  printf("%llu\n", n);

  return 0;
}
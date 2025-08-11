#include <stdio.h>

long long pow_(unsigned long long x, long long d, long long n) {
  long long result = 1;
  x %= n;
  while (d > 0) {
    if (d & 1) result = (result * x) % n;
    x = (x * x) % n;
    d >>= 1;
  }
  return result;
}

int miller_rabin(const long long n) {
  if (n == 2 || n == 3) return 1;
  if (n < 2 || n % 2 == 0) return 0;

  int s = 0;
  long long d = n - 1;
  while (d % 2 == 0) {
    d /= 2;
    s++;
  }

  const int a_list[7] = {2, 3, 5, 7, 11, 13, 17};
  for (int a_i = 0; a_i < 7; a_i++) {
    const long long a = a_list[a_i];
    if (a >= n) break;
    unsigned long long x = a;
    x = pow_(x, d, n);
    if (x == 1 || x == n-1) continue;
    int flag = 0;
    for (int i = 0; i < s-1; i++) {
      x = pow_(x, 2, n);
      if (x == n-1) {
        flag = 1;
        break;
      }
    }
    if (!flag) return 0;
  }
  return 1;
}

int main(void) {
  int len, count=0;
  long long n;
  scanf("%d", &len);
  for (int i = 0; i < len; i++) {
    scanf("%lld", &n);
    count += miller_rabin(2*n+1);
  }

  printf("%d\n", count);

  return 0;
}
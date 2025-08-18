#include <stdio.h>
#define ll long long

ll pow_(ll x, ll y, ll n) {
  __uint128_t result = 1;
  __uint128_t base = x;
  while (y != 0) {
    if (y & 1) result = (result * base) % n;
    base = (base * base) % n;
    y >>= 1;
  }
  return (ll)result;
}

int miller_rabin(ll n) {
  if (n == 2 || n == 3) return 1;
  if (n < 2 || n % 2 == 0) return 0;

  ll s = 0, d = n - 1;
  while (d % 2 == 0) {
    d /= 2;
    s++;
  }

  int a_list[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
  for (int a_i = 0; a_i < 12; a_i++) {
    ll a = a_list[a_i];
    ll x = a % n;
    if (a >= n) break;

    x = pow_(x, d, n);
    if (x == 1 || x == n - 1) continue;
    int flag = 0;
    for (int i = 0; i < s-1; i++) {
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

int main(void) {
  ll a, b;
  scanf("%lld %lld", &a, &b);

  for (ll i = a; i <= b; i++) {
    if (miller_rabin(i) || i == 9) printf("%lld ", i);
  }

  return 0;
}
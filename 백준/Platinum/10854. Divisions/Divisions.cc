#include <iostream>
#include <map>
#include <random>
#include <chrono>
#define ull unsigned long long

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ull gcd(ull a, ull b) {
  while (b != 0) {
    const ull temp = a;
    a = b;
    b = temp % b;
  }
  return a;
}

ull power_(ull x, ull d, ull n) {
  __int128 res = 1, a = x;
  while (d) {
    if (d & 1) res = (res * a) % n;
    a = (a * a) % n;
    d >>= 1;
  }
  return (ull)res;
}

bool miller_rabin(ull n) {
  ull d = n - 1, s = 0;
  while (d % 2 == 0) {
    d >>= 1;
    s++;
  }

  for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23}) {
    if (a >= n) break;
    ull x = power_(a, d, n);
    if (x == 1 || x == n - 1) continue;
    bool flag = true;
    for (int r = 0; r < s - 1; r++) {
      x = power_(x, 2, n);
      if (x == n - 1) {
        flag = false;
        break;
      }
    }
    if (flag) {
      return false;
    }
  }
  return true;
}

bool is_prime(ull n) {
  if (n < 2) return false;
  if (n == 2 || n == 3) return true;
  if (n % 2 == 0) return false;
  return miller_rabin(n);
}

ull pollard_rho(ull n) {
  if (is_prime(n)) return n;
  for (int i : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 47, 53, 59, 61}) {
    if (n % i == 0) return i;
  }

  for (int attempt = 0; attempt < 20; attempt++) {
    ull x = rng() % (n-2) + 2;
    ull y = x, d = 1, c = rng() % 10 + 1;

    ull product = 1;
    int batch_size = 127;

    while (d == 1) {
      for (int i = 0; i < batch_size && d == 1; i++) {
        x = (__int128(x) * x + c) % n;
        y = (__int128(y) * y + c) % n;
        y = (__int128(y) * y + c) % n;
        product = (__int128(product) * (x > y ? x - y : y - x)) % n;
      }
      d = gcd(product, n);
    }
    if (d != n) {
      if (is_prime(d)) return d;
      return pollard_rho(d);
    }
  }
  for (ull i = 2; i * i <= n; i++) {
    if (n % i == 0) return i;
  }
  return n;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  ull n;
  cin >> n;
  map<ull, int> primes;
  while (n > 1) {
    ull prime = pollard_rho(n);
    primes[prime]++;
    n /= prime;
  }

  ull answer = 1;
  for (auto [key, value] : primes) {
    answer *= value + 1;
  }

  cout << answer << '\n';
}
#include <stdio.h>
#include <stdlib.h>

unsigned long long int pow_(unsigned long long int a, unsigned long long int b, unsigned long long int mod) {
  __uint128_t result = 1;
  __uint128_t base = a%mod;
  while (b > 0) {
    if (b & 1) result = (result * base) % mod;
    base = (base * base) % mod;
    b >>= 1;
  }
  return (unsigned long long int) result;
}

unsigned long long int gcd(unsigned long long int a, unsigned long long int b) {
  while (b != 0) {
    const unsigned long long int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int miller_rabin(unsigned long long int n) {
  int s = 0;
  unsigned long long int d = n - 1;
  while (d % 2 == 0) {
    d /= 2;
    s++;
  }

  int a_list[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
  for (int a_i = 0; a_i < 12; a_i++) {
    long long int a = a_list[a_i];
    unsigned long long int x = a;
    x = pow_(x, d, n);
    if (x == 1 || x == n - 1) continue;
    int flag = 0;
    for (int i = 0; i < s - 1; i++) {
      x = pow_(x, 2, n);
      if (x == n - 1)  {
        flag = 1;
        break;
      }
    }
    if (!flag) return 0;
  }

  return 1;
}

int is_prime(unsigned long long int n) {
  if (n <= 71) {
    const int temp_list[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
    for (int i = 0; i < 20; i++) {
      if (n == temp_list[i]) return 1;
    }
    return 0;
  }
  return miller_rabin(n);
}

__uint128_t g(__uint128_t x, unsigned long long int mod) {
  return ((x * x) + 1) % mod;
}

unsigned long long int pollard_rho(unsigned long long int n, unsigned long long int x) {
  if (is_prime(n)) return n;
  int temp_list[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
  for (int i = 0; i < 20; i++) {
    if (n%temp_list[i] == 0) return temp_list[i];
  }

  __uint128_t temp = x, y = x, d = 1;

  while (1) {
    while (d == 1) {
      x = g(x, n);
      y = g(g(y, n), n);
      if (x > y) d = gcd(x-y, n);
      else d = gcd(y-x, n);
    }
    if (d == n) {
      temp++;
      x = temp, y = temp;
      d = 1;
    }else {
      if (miller_rabin(d)) return d;
      return pollard_rho(d, 2);
    }
  }
}

void merge(unsigned long long int* arr, long long int left, long long int mid, long long int right) {
  long long int n1 = mid - left + 1;
  long long int n2 = right - mid;
  unsigned long long int* g1 = (unsigned long long int*)malloc(sizeof(unsigned long long int) * n1);
  unsigned long long int* g2 = (unsigned long long int*)malloc(sizeof(unsigned long long int) * n2);

  for (int i = 0; i < n1; i++) g1[i] = arr[left + i];
  for (int i = 0; i < n2; i++) g2[i] = arr[mid + 1 + i];

  long long int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (g1[i] <= g2[j]) arr[k++] = g1[i++];
    else arr[k++] = g2[j++];
  }
  while (i < n1) arr[k++] = g1[i++];
  while (j < n2) arr[k++] = g2[j++];

  free(g1);
  free(g2);
}

void merge_sort(unsigned long long int* arr, const long long int left, const long long int right) {
  if (left < right) {
    const long long int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}

int main(void) {
  unsigned long long int n, answer[10000];
  long long int len = 0;
  scanf("%lld", &n);

  while (n != 1) {
    const unsigned long long int prime = pollard_rho(n, 2);
    answer[len++] = prime;
    n /= prime;
  }

  merge_sort(answer, 0, len - 1);

  for (int i = 0; i < len; i++) printf("%lld\n", answer[i]);

  return 0;
}
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  int ten = 0, temp = n;
  while (temp > 0) {
    ten++;
    temp /= 10;
  }

  int start = n - (ten * 9);
  for (int i = start; i <= n; i++) {
    int sum = i;
    temp = i;
    while (temp > 0) {
      sum += temp % 10;
      temp /= 10;
    }

    if (sum == n) {
      cout << i << '\n';
      return 0;
    }
  }

  cout << 0 << '\n';
  return 0;
}
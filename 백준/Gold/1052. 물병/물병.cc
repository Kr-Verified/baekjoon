#include <iostream>

using namespace std;

int count(int n) {
  int count = 0;
  while (n) {
    count += (n&1);
    n >>= 1;
  }
  return count;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, k;
  cin >> n >> k;

  int zero = 0;
  while (count(n) > k) {
    n++;
    zero++;
  }

  cout << zero << '\n';

  return 0;
}
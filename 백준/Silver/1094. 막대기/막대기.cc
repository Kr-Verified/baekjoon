#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int x;
  cin >> x;

  int answer = 0;
  while (x > 0) {
    if (x & 1) answer++;
    x >>= 1;
  }

  cout << answer << '\n';

  return 0;
}
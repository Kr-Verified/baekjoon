#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  long long int result = 1;
  for (int i = 1; i <= n; i++) result *= i;

  cout << result;
  return 0;
}
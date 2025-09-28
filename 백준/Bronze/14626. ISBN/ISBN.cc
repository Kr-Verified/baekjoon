#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int result = 0;
  int idx = 0;
  string input;
  cin >> input;

  for (int i = 0; i < input.length(); i++) {
    if (input[i] != '*') result = (result + (input[i] - '0') * (i % 2 == 1 ? 3 : 1)) % 10;
    else idx = i;
  }

  int v = (idx % 2 == 1 ? 3 : 1);
  if (result == 0) cout << 0 << '\n';
  else for (int i = 0; i < 10; i++) {
    if ((i * v + result) % 10 == 0) cout << i << '\n';
  }

  return 0;
}
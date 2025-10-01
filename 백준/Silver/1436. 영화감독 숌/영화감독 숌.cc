#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, cnt = 0;
  cin >> n;
  while (n > 0) {
    cnt++;
    if (to_string(cnt).find("666") != string::npos) n--;
  }

  cout << cnt << '\n';

  return 0;
}
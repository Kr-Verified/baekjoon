#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int result = 0, input;
    for (int i = 0; i < n; i++) {
      cin >> input;
      result += input;
    }
    cout << result << '\n';
  }
}
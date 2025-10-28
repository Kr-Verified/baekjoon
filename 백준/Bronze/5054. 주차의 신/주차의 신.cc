#include <iostream>
#include <vector>

using namespace std;

int abs(int a) {
  return a < 0 ? -a : a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, max = -1, min = 100;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      if (v[i] > max) max = v[i];
      if (v[i] < min) min = v[i];
    }

    cout << (max-min)*2 << '\n';
  }
  return 0;
}
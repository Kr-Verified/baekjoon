#include <iostream>
#include <vector>

using namespace std;

int dp(vector<vector<int>> &v, int k, int n) {
  if (v[k][n] != 0) return v[k][n];
  if (k > 0) v[k][n] += dp(v, k - 1, n);
  if (n > 1) v[k][n] += dp(v, k, n - 1);
  return v[k][n];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t, k, n;
  vector<vector<int>> v(15, vector<int>(15, 0));
  for (int i = 1; i < 15; i++) v[0][i] = i;
  cin >> t;
  while (t--) {
    cin >> k >> n;
    cout << dp(v, k, n) << '\n';
  }

  return 0;
}
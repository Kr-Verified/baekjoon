#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  vector<pair<int, int>> v(n);
  vector<int> rank(n, 1);
  for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

  for (int i = 0; i < n; i++) {
    int sw = v[i].first;
    int sh = v[i].second;
    for (int j = 0; j < n; j++) {
      int w = v[j].first;
      int h = v[j].second;
      if (sw < w && sh < h) rank[i]++;
    }
  }

  for (int i = 0; i < n; i++) cout << rank[i] << ' ';

  return 0;
}
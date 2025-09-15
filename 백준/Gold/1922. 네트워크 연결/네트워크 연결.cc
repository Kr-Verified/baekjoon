#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int find(vector<int> &parent, int x) {
  if (parent[x] < 0) return x;
  return parent[x] = find(parent, parent[x]);
}

bool unite(vector<int> &parent, int x, int y) {
  int root_x = find(parent, x);
  int root_y = find(parent, y);
  if (root_x == root_y) return false;
  if (parent[root_x] < parent[root_y]) {
    parent[root_x] += parent[root_y];
    parent[root_y] = root_x;
  }else {
    parent[root_y] += parent[root_x];
    parent[root_x] = root_y;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m, a, b, c, result = 0, cnt = 0;
  cin >> n >> m;
  vector<int> parent(n, -1);
  vector<pair<int, pair<int, int>>> edges;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    edges.push_back(make_pair(c, make_pair(a-1, b-1)));
  }

  sort(edges.begin(), edges.end());

  for (auto [cost, pos] : edges) {
    if (unite(parent, pos.first, pos.second)) {
      result += cost;
      cnt++;
      if (cnt == n-1) break;
    }
  }

  cout << result << '\n';

  return 0;
}
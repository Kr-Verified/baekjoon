#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main() {
  int n, m, x1, y1, x2, y2;
  vector<pair<int, int>> d(4);
  d[0] = make_pair(-1, 0);
  d[1] = make_pair(1, 0);
  d[2] = make_pair(0, -1);
  d[3] = make_pair(0, 1);
  vector<vector<int>> field(501, vector<int>(501, 0));
  cin >> n;
  for (int k = 0; k < n; k++) {
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    for (int i = x1; i <= x2; i++) {
      for (int j = y1; j <= y2; j++) {
        field[i][j] = 1;
      }
    }
  }
  cin >> m;
  for (int k = 0; k < m; k++) {
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    for (int i = x1; i <= x2; i++) {
      for (int j = y1; j <= y2; j++) {
        field[i][j] = -1;
      }
    }
  }
  priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> q;
  vector<vector<int>> dist(501, vector<int>(501, 1e9));
  dist[0][0] = 0;
  q.push({0, {0, 0}});
  while (!q.empty()) {
    auto [weight, pos] = q.top();
    auto [x, y] = pos;
    q.pop();
    if (x == 500 && y == 500) {
      cout << weight << "\n";
      return 0;
    }
    for (int i = 0; i < 4; i++) {
      int dx = x + d[i].first;
      int dy = y + d[i].second;
      if (dx >= 0 && dx <= 500 && dy >= 0 && dy <= 500 && field[dx][dy] != -1) {
        const int new_weight = weight + field[dx][dy];
        if (new_weight < dist[dx][dy]) {
          dist[dx][dy] = new_weight;
          q.push({new_weight, {dx, dy}});
        }
      }
    }
  }

 cout << -1 << endl;

  return 0;
}
#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> graph(n);

  for (int i = 0; i < n - 1; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    u--; v--;
    graph[u].push_back(make_pair(v, c));
    graph[v].push_back(make_pair(u, c));
  }

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    queue<int> q;
    q.push(u);
    vector<int> dist(n, -1);
    dist[u] = 0;
    while (!q.empty()) {
      int p = q.front();
      q.pop();
      for (auto next : graph[p]) {
        if (dist[next.first] == -1) {
          dist[next.first] = dist[p] + next.second;
          q.push(next.first);
        }
      }
    }
    cout << dist[v] << endl;
  }

  return 0;
}
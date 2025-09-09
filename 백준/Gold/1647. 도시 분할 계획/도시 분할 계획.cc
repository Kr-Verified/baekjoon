#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct Edge{
  int u, v, cost;
  bool operator<(const Edge& p) const {
    return cost > p.cost;
  }
} Edge;

int find(int x, vector<int>& parent) {
  if (parent[x] < 0) return x;
  return parent[x] = find(parent[x], parent);
}

bool union_(int x, int y, vector<int>& parent) {
  int root_x = find(x, parent);
  int root_y = find(y, parent);
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

int kruskal(int n, priority_queue<Edge>& pq, vector<int>& parent) {
  int mst_weight = 0, max_edges = 0;
  while (!pq.empty()) {
    Edge e = pq.top();
    pq.pop();
    if (union_(e.u, e.v, parent)) {
      mst_weight += e.cost;
      if (e.cost > max_edges) max_edges = e.cost;
    }
  }
  return mst_weight - max_edges;
}

int main() {
  int n, m;
  ios::sync_with_stdio(false);
  cin >> n >> m;
  priority_queue<Edge> pq;
  vector<int> parent(n+1, -1);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    pq.push({a, b, c});
  }
  int result = kruskal(n, pq, parent);

  cout << result << endl;

  return 0;
}
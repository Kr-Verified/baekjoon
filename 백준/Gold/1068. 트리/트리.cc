#include <iostream>
#include <vector>
#include <queue>

using namespace std;



int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, node;
  cin >> n;
  vector<int> tree(n);
  for (int i = 0; i < n; i++) cin >> tree[i];
  cin >> node;

  vector<bool> deleted(n, false);
  queue<int> q;
  q.push(node);
  deleted[node] = true;
  while (!q.empty()) {
    auto del_node = q.front();
    q.pop();
    for (int i = 0; i < n; i++) {
      if (del_node == tree[i] && !deleted[i]) {
        q.push(i);
        deleted[i] = true;
      }
    }
  }

  int root = -1;
  for (int i = 0; i < n; i++) if (tree[i] == -1) root = i;
  if (deleted[root]) {
    cout << 0 << '\n';
    return 0;
  }

  vector<bool> visited(n, false);
  q = queue<int>();
  q.push(root);
  visited[root] = true;
  int result = 0;
  while (!q.empty()) {
    auto vertex = q.front();
    q.pop();
    bool is_leaf = true;
    for (int i = 0; i < n; i++) {
      if (vertex == tree[i] && !visited[i] && !deleted[i]) {
        q.push(i);
        visited[i] = true;
        is_leaf = false;
      }
    }
    if (is_leaf) result++;
  }

  cout << result << '\n';

  return 0;
}
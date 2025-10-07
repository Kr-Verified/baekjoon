#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, m, temp;
    cin >> n >> m;
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
      cin >> temp;
      q.push({temp, i});
      pq.push(temp);
    }

    int cnt = 0;
    while (!q.empty()) {
      auto [val, idx] = q.front();
      q.pop();
      if (pq.top() == val) {
        pq.pop();
        cnt++;
        if (idx == m) {
          cout << cnt << '\n';
          break;
        }
      }else q.push({val, idx});
    }

  }

  return 0;
}
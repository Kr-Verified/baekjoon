#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int abs(int a) {
  return (a > 0) ? a : -a;
}

struct cmp {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
      return a.second > b.second;
    }
    return a.first > b.first;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> pq;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    if (k == 0) {
      if (!pq.empty()) {
        cout << pq.top().second << '\n';
        pq.pop();
      }else cout << "0\n";
    }else pq.push(make_pair(abs(k), k));
  }

  return 0;
}
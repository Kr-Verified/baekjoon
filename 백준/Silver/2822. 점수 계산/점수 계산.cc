#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

struct minCom {
  bool operator()(const int &a, const int &b) const {
    return a > b;
  };
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  priority_queue<pair<int, int>> pq;

  int n;
  for (int i = 1; i <= 8; i++ ) {
    cin >> n;
    pq.push({n, i});
  }

  priority_queue<int, vector<int>, minCom> pq2;
  n = 0;
  for (int i = 1; i <= 5; i++) {
    n += pq.top().first;
    pq2.push(pq.top().second);
    pq.pop();
  }
  cout << n << '\n';
  for (int i = 1; i <= 5; i++) {
    cout << pq2.top() << " ";
    pq2.pop();
  }
}
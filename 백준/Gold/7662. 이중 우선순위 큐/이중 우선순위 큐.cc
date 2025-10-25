#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

struct cmp {
  bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first > b.first;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int k, value;
    char cmd;
    priority_queue<pair<int, int>> pqb;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pqs;
    cin >> k;
    vector<bool> v(k, false);

    for (int i = 0; i < k; i++) {
      cin >> cmd >> value;
      if (cmd == 'I') {
        pqb.push(make_pair(value, i));
        pqs.push(make_pair(value, i));
      } else if (cmd == 'D') {
        if (value == -1) {
          while (!pqs.empty() && v[pqs.top().second]) pqs.pop();
          if (!pqs.empty()) {
            v[pqs.top().second] = true;
            pqs.pop();
          }
        }else if (value == 1) {
          while (!pqb.empty() && v[pqb.top().second]) pqb.pop();
          if (!pqb.empty()) {
            v[pqb.top().second] = true;
            pqb.pop();
          }
        }
      }
    }

    while (!pqs.empty() && v[pqs.top().second]) pqs.pop();
    while (!pqb.empty() && v[pqb.top().second]) pqb.pop();
    if (pqs.empty() || pqb.empty()) cout << "EMPTY\n";
    else {
      cout << pqb.top().first << ' ' << pqs.top().first << '\n';
    }
  }

  return 0;
}
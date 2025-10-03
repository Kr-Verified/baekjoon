#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct Data {
  int val, left, right;
} Data;

struct cmp {
  bool operator()(Data a, Data b) {
    return a.val > b.val;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, k, temp, prev, result = 0;
  cin >> n >> k >> prev;
  priority_queue<Data, vector<Data>, cmp> pq;
  Data point[100001];
  for (int i = 1; i < n; i++) {
    cin >> temp;
    const int diff = temp - prev;
    pq.push(Data{diff, i, i + 1});
    point[i].val = diff;
    point[i].left = i - 1;
    point[i].right = i + 1;
    prev = temp;
  }
  point[n] = Data{0, n - 1, n + 1};

  while (!pq.empty())
  {
    Data data_temp = pq.top();
    pq.pop();
    int cur_left = data_temp.left, cur_right = data_temp.right;
    if (cur_left > 0 && cur_right <= n && cur_right == point[cur_left].right && cur_left == point[cur_right].left) {
      result += data_temp.val;
      if (--k <= 0) break;
      int prev_left = point[cur_left].left, next_right = point[cur_right].right;
      point[prev_left].val = point[prev_left].val + point[cur_right].val - data_temp.val;
      point[prev_left].right = next_right;
      point[next_right].left = prev_left;
      data_temp.left = prev_left;
      data_temp.right = next_right;
      data_temp.val = point[prev_left].val;
      pq.push(data_temp);
    }
  }

  cout << result << '\n';

  return 0;
}
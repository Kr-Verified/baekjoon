#include <iostream>
#include <vector>

using namespace std;

void build(const vector<int> &arr, vector<int> &tree, const int node, const int start, const int end) {
  if (start == end) tree[node] = start;
  else {
    const int mid = start + (end - start) / 2;
    build(arr, tree, node * 2, start, mid);
    build(arr, tree, node * 2 + 1, mid + 1, end);
    const int left = tree[node * 2];
    const int right = tree[node * 2 + 1];
    if (arr[left] <= arr[right]) tree[node] = left;
    else tree[node] = right;
  }
}

void update(vector<int> &arr, vector<int> &tree, const int node, const int idx, const int value, const int start, const int end) {
  if (start == end) {
    arr[idx] = value;
    tree[node] = idx;
  }
  else {
    const int mid = start + (end - start) / 2;
    if (idx <= mid) {
      update(arr, tree, node * 2, idx, value, start, mid);
    }else {
      update(arr, tree, node * 2 + 1, idx, value, mid + 1, end);
    }
    const int left = tree[node * 2];
    const int right = tree[node * 2 + 1];
    if (arr[left] <= arr[right]) tree[node] = left;
    else tree[node] = right;
  }
}

int query(const vector<int> &arr, const vector<int> &tree, const int node, const int start, const int end, const int left, const int right) {
  if (right < start || left > end) return -1;
  if (left <= start && end <= right) return tree[node];
  const int mid = start + (end - start) / 2;
  const int lq = query(arr, tree, node * 2, start, mid, left, right);
  const int rq = query(arr, tree, node * 2 + 1, mid + 1, end, left, right);
  if (lq == -1 && rq == -1) return -1;
  if (lq == -1) return rq;
  if (rq == -1) return lq;
  if (arr[lq] <= arr[rq]) return lq;
  return rq;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m, a, b, c;
  cin >> n;
  vector<int> arr(n);
  vector<int> tree(n * 4);
  for (int i = 0; i < n; i++) cin >> arr[i];
  build(arr, tree, 1, 0, n - 1);
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    if (a == 1) {
      update(arr, tree, 1, b - 1, c, 0, n - 1);
    }else {
      cout << query(arr, tree, 1, 0, n - 1, b - 1, c - 1)+1 << "\n";
    }
  }
  return 0;
}
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>

using namespace std;

int block_size;

typedef struct {
  int idx, left, right;
} Query;

bool cmp(Query a, Query b) {
  if (a.left/block_size != b.left/block_size) return a.left/block_size < b.left/block_size;
  if (a.right == b.right) return a.left < b.left;
  return a.right < b.right;
}

int main() {
  int n, m;
  scanf("%d", &n);
  vector<int> arr(n);
  vector<int> sum(n+1, 0);
  sum[0] = n;
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    sum[i+1] = sum[i] + arr[i];
  }
  scanf("%d", &m);
  vector<Query> queries(m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &queries[i].left, &queries[i].right);
    queries[i].idx = i;
    queries[i].left--;
  }
  block_size = sqrt(n);
  sort(queries.begin(), queries.end(), cmp);

  vector<int> answer(m);
  list<int> idx[100003 * 2];
  int count[100001] = {0};
  int ml = queries[0].left, mr = queries[0].right, cur_max = 0;
  for (int i = ml; i <= mr; i++) {
    int value = sum[i];
    if (idx[value].size() >= 2) {
      count[idx[value].back() - idx[value].front()]--;
    }
    idx[value].push_back(i);
    if (idx[value].size() >= 2) {
      int ii = idx[value].back() - idx[value].front();
      count[ii]++;
      cur_max = max(cur_max, ii);
    }
  }
  answer[queries[0].idx] = cur_max;
  count[0] = n+2;
  for (int i = 1; i < m; i++) {
    const int l = queries[i].left, r = queries[i].right;
    while (ml > l) {
      int value = sum[--ml];
      if (idx[value].size() >= 2) {
        count[idx[value].back() - idx[value].front()]--;
      }
      idx[value].push_front(ml);
      if (idx[value].size() >= 2) {
        int ii = idx[value].back() - idx[value].front();
        count[ii]++;
        cur_max = max(cur_max, ii);
      }
    }
    while (mr < r) {
      int value = sum[++mr];
      if (idx[value].size() >= 2) {
        count[idx[value].back() - idx[value].front()]--;
      }
      idx[value].push_back(mr);
      if (idx[value].size() >= 2) {
        int ii = idx[value].back() - idx[value].front();
        count[ii]++;
        cur_max = max(cur_max, ii);
      }
    }
    while (ml < l) {
      int value = sum[ml];
      if (idx[value].size() >= 2) {
        count[idx[value].back() - idx[value].front()]--;
      }
      idx[value].pop_front();
      if (idx[value].size() >= 2) {
        int ii = idx[value].back() - idx[value].front();
        count[ii]++;
        cur_max = max(cur_max, ii);
      }
      ml++;
    }
    while (mr > r) {
      int value = sum[mr];
      if (idx[value].size() >= 2) {
        count[idx[value].back() - idx[value].front()]--;
      }
      idx[value].pop_back();
      if (idx[value].size() >= 2) {
        int ii = idx[value].back() - idx[value].front();
        count[ii]++;
        cur_max = max(cur_max, ii);
      }
      mr--;
    }
    while (count[cur_max] == 0 && cur_max > 0) cur_max--;
    answer[queries[i].idx] = cur_max;
  }

  for(int i = 0; i < m; i++) printf("%d\n", answer[i]);

  return 0;
}
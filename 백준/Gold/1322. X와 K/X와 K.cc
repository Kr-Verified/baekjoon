#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long x, k;
  cin >> x >> k;

  long long zero_cnt = 0, order;
  for (order = 0; ; ++order) {
    if (!(x & ((long long)1<<order))) {
      zero_cnt++;
      if (((long long)1 << zero_cnt) - 1 >= k) break;
    }
  }

  long long y = 0;
  while (order >= 0 && zero_cnt > 0 && k > 0) {
    if (!(x & ((long long)1 << order))) {
      if (((long long)1 << (zero_cnt - 1)) <= k) {
        y |= ((long long)1 << (order));
        k -= (long long)1 << (zero_cnt - 1);
      }
      zero_cnt--;
    }
    order--;
  }

  cout << y << '\n';

  return 0;
}
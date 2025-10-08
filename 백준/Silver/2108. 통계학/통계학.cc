#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, avg = 0, mid, most = 0, range;
  vector<int> cnt(8001, 0);
  cin >> n;

  vector<int> v(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    avg += v[i];
    cnt[v[i]+4000]++;
    if (cnt[v[i]+4000] > cnt[most+4000]) most = v[i];
  }

  avg = round((double)avg/n);
  sort(v.begin(), v.end());
  mid = v[n / 2];
  int seq = 0;
  for (int i = -4000; i <= 4000; i++) {
    if (cnt[i+4000] == cnt[most+4000] && seq < 2) {
      most = i;
      seq++;
    }
    if (seq == 2) break;
  }
  range = v[n - 1] - v[0];

  cout << (avg == 0 ? 0 : avg) << '\n';
  cout << mid << '\n';
  cout << most << '\n';
  cout << range << '\n';

  return 0;
}
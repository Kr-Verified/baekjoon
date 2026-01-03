#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, max=0, cnt=0, total=0, idx=0;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      total += p[i];
      if (max < p[i]) {
        max = p[i];
        idx = i+1;
        cnt = 0;
      }else if (max == p[i]) cnt++;
    }
    if (cnt > 0) cout << "no winner\n";
    else cout << (max*2 > total ? "majority winner":"minority winner") << " " << idx << "\n";
  }

  return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int x1, y1, r1, x2, y2, r2, t;
  cin >> t;
  for (int i = 0; i < t; i++) {
      cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
      int d = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
      int cond1 = (r1 + r2)*(r1 + r2);
      int cond2 = (r1 - r2)*(r1 - r2);
      if (d == 0) {
        if (cond2 == 0) cout << -1 << '\n';
        else cout << 0 << '\n';
      }else if (d == cond1 || d == cond2) cout << 1 << '\n';
      else if (d < cond1 && d > cond2) cout << 2 << '\n';
      else cout << 0 << '\n';
  }

  return 0;
}
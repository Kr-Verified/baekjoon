#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int l=1, p=1, v=1, cnt=1;
  while (true) {
    cin >> l >> p >> v;
    if (l==0 && p==0 && v==0) break;
    cout << "Case " << cnt++ << ": " << (v/p*l)+(v%p<l?v%p:l) << "\n";
  }

  return 0;
}
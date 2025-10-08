#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, sum = 0, temp, cnt = 0;
  cin >> n;
  temp = n;
  while (temp > 0) {
    sum += temp % 10;
    temp /= 10;
  }

  temp = n;
  for (int i = 2; i * i <= n; i++) {
    if (temp % i == 0) {
      cnt++;
      while (temp % i == 0) temp /= i;
    }
  }
  if (temp > 1) cnt++;

  bool 이면수 = false, 임현수 = false;

  if (n != 5 && n >= 4 && sum & 1) 이면수 = true;
  if (n == 4 || n == 2 || (cnt != 0 && !(cnt&1))) 임현수 = true;

  if (임현수 && 이면수) cout << "4\n";
  else if (임현수) cout << "2\n";
  else if (이면수) cout << "1\n";
  else cout << "3\n";
}
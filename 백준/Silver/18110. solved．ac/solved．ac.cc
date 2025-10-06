#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, result = 0;
  cin >> n;
  if (n == 0) {
    cout << 0 << '\n';
    return 0;
  }

  vector<int> difs(n);
  for (int i = 0; i < n; i++) cin >> difs[i];

  sort(difs.begin(), difs.end());

  int remove = round(difs.size()*0.15);
  for (int i = remove; i < difs.size()-remove; i++) result += difs[i];

  cout << round((double)result/(difs.size()-2*remove)) << '\n';

  return 0;
}
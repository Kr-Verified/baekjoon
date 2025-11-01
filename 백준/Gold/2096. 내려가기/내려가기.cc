#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, temp0, temp2;
  cin >> n;
  vector<int> field(3, 0);
  vector<int> maxDp(3, 0);
  vector<int> minDp(3, 0);

  for (int i = 0; i < n; i++) {
    cin >> field[0] >> field[1] >> field[2];

    temp0 = maxDp[0], temp2 = maxDp[2];
    maxDp[0] = max(maxDp[0], maxDp[1]) + field[0];
    maxDp[2] = max(maxDp[1], maxDp[2]) + field[2];
    maxDp[1] = max(max(temp0, maxDp[1]), temp2) + field[1];

    temp0 = minDp[0], temp2 = minDp[2];
    minDp[0] = min(minDp[0], minDp[1]) + field[0];
    minDp[2] = min(minDp[2], minDp[1]) + field[2];
    minDp[1] = min(min(temp0, minDp[1]), temp2) + field[1];
  }

  int max_r = maxDp[0], min_r = minDp[0];

  for (int i = 1; i < 3; i++) {
    if (max_r < maxDp[i]) max_r = maxDp[i];
    if (min_r > minDp[i]) min_r = minDp[i];
  }
  cout << max_r << ' ' << min_r << endl;

  return 0;
}
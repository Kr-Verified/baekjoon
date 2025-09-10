#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n;
  vector<int> cards(n);
  for (int i = 0; i < n; i++) cin >> cards[i];

  cin >> m;
  vector<int> goals(m);
  for (int i = 0; i < m; i++) cin >> goals[i];

  sort(cards.begin(), cards.end());
  for (int i = 0; i < m; i++) {
    auto start = lower_bound(cards.begin(), cards.end(), goals[i]);
    auto end = upper_bound(cards.begin(), cards.end(), goals[i]);
    cout << (end - start) << " ";
  }

  return 0;
}
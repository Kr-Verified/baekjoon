#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m, input;
  cin >> n >> m;

  set<int> a, b, diffa, diffb, res;
  for (int i = 0; i < n; i++) {
    cin >> input;
    a.insert(input);
  }
  for (int i = 0; i < m; i++) {
    cin >> input;
    b.insert(input);
  }

  set_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(diffa, diffa.begin()));
  set_difference(b.begin(), b.end(), a.begin(), a.end(), inserter(diffb, diffb.begin()));

  set_union(diffa.begin(), diffa.end(), diffb.begin(), diffb.end(), inserter(res, res.begin()));

  cout << res.size() << '\n';

  return 0;
}
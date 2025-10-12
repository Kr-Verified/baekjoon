#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  string domain, pw;
  cin >> n >> m;

  unordered_map<string, string> map;
  for (int i = 0; i < n; i++) {
    cin >> domain >> pw;
    map[domain] = pw;
  }

  for (int i = 0; i < m; i++) {
    cin >> domain;
    cout << map[domain] << '\n';
  }

  return 0;
}
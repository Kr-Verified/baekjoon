#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    unordered_map<string, int> clothes;

    for (int i = 0; i < n; i++) {
      string name, kind;
      cin >> name >> kind;
      clothes[kind]++;
    }

    int result = 1;
    for (auto &p : clothes) {
      result *= (p.second + 1);
    }
    cout << result-1 << '\n';
  }
  return 0;
}
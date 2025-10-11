#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool isNumber(const string& s) {
  return !s.empty() && all_of(s.begin(), s.end(), [](unsigned char c) { return isdigit(c); });
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  string input;
  cin >> n >> m;

  unordered_map<int, string> v_int;
  unordered_map<string, int> v_string;
  for (int i = 1; i <= n; i++) {
    cin >> input;
    v_int[i] = input;
    v_string[input] = i;
  }

  for (int i = 0; i < m; i++) {
    cin >> input;
    bool number = isNumber(input);
    if (number) {
      cout << v_int[stoi(input)] << '\n';
    }else {
      cout << v_string[input] << '\n';
    }
  }

  return 0;
}
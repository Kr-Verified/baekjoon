#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    bool is_vaild = true;
    int cnt = 0;
    for (int j = 0; j < s.length(); j++) {
      if (s[j] == '(') cnt++;
      else if (s[j] == ')') cnt--;
      if (cnt < 0) {
        is_vaild = false;
        break;
      }
    }
  if (cnt != 0) is_vaild = false;
  cout << (is_vaild ? "YES" : "NO") << endl;
  }

  return 0;
}
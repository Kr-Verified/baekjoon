#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string input;
  stack<char> s;

  while (1) {
    getline(cin, input);
    if (input == ".") break;
    s = stack<char>();
    bool is_valid = true;
    for (int i = 0; i < input.length(); i++) {
      if (input[i] == '(') s.push('(');
      else if (input[i] == '[') s.push('[');
      else if (input[i] == ')') {
        if (!s.empty() && s.top() == '(') s.pop();
        else {
          is_valid = false;
          break;
        }
      }else if (input[i] == ']')
      {
        if (!s.empty() && s.top() == '[') s.pop();
        else {
          is_valid = false;
          break;
        }
      }
    }
    if (s.empty() && is_valid) cout << "yes" << '\n';
    else cout << "no" << '\n';
  }

  return 0;
}
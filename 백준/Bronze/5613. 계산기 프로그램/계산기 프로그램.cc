#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, result;
  char oper;
  cin >> result;
  while (1) {
    cin >> oper;
    if (oper == '=') break;
    cin >> n;
    if (oper == '+') result += n;
    else if (oper == '-') result -= n;
    else if (oper == '*') result *= n;
    else if (oper == '/') result /= n;
  }

  cout << result << '\n';

  return 0;
}
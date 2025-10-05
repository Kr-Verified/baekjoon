#include <iostream>
#include <stack>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  stack<int> s;
  int n, temp, result = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    if (temp == 0 && !s.empty()) {
      result -= s.top();
      s.pop();
    }else {
      s.push(temp);
      result += temp;
    }
  }

  cout << result << '\n';

  return 0;
}
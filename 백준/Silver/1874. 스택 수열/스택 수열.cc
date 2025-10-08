#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, input;
  cin >> n;

  queue<int> arr;
  queue<char> result;
  for (int i = 0; i < n; i++) {
    cin >> input;
    arr.push(input);
  }

  stack<int> s;
  int top = 0;
  bool failed = false;
  while (!arr.empty()) {
    if (s.empty() || s.top() < arr.front()) {
      if (top >= arr.front()) {
        failed = true;
        break;
      }else {
        s.push(++top);
        result.push('+');
      }
    }else {
      if (s.top() == arr.front()) arr.pop();
      s.pop();
      result.push('-');
    }
  }

  if (failed) cout << "NO\n";
  else {
    while (!result.empty()) {
      cout << result.front() << '\n';
      result.pop();
    }
  }

  return 0;
}
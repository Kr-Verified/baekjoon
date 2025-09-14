#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, value;
  string command;
  queue<int> q;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> command;
    if (command == "push") {
      cin >> value;
      q.push(value);
    }else {
      if (command == "pop") {
        if (!q.empty()) {
          cout << q.front() << '\n';
          q.pop();
        }else cout << -1 << '\n';
      }else if (command == "size") {
        cout << q.size() << '\n';
      }else if (command == "empty") cout << q.empty() << '\n';
      else if (command == "front") cout << (q.empty() ? -1 : q.front()) << '\n';
      else if (command == "back") cout << (q.empty() ? -1 : q.back()) << '\n';
    }
  }

  return 0;
}
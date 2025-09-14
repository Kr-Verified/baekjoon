#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, value;
  string command;
  stack<int> st;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> command;
    if (command == "push") {
      cin >> value;
      st.push(value);
    }else {
      if (command == "pop") {
        cout << (st.empty()?-1:st.top()) << '\n';
        if (!st.empty()) st.pop();
      }else if (command == "top") {
        cout << (st.empty()?-1:st.top()) << "\n";
      }else if (command == "empty") cout << st.empty() << "\n";
      else if (command == "size") cout << st.size() << "\n";
    }
  }

  return 0;
}
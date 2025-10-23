#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    bool reversed = false;
    bool errored = false;
    string cmd;
    cin >> cmd;

    int n;
    cin >> n;

    deque<int> dq;
    string input, num;
    cin >> input;
    for (char c : input) {
      if (isdigit(c)) num += c;
      else if (c == ',' || c == ']') {
        if (!num.empty()) {
          dq.push_back(stoi(num));
          num = "";
        }
      }
    }

    for (char c : cmd) {
      if (c == 'R') reversed = !reversed;
      else if (c == 'D') {
        if (dq.empty()) {
          cout << "error\n";
          errored = true;
          break;
        }else {
          if (!reversed) dq.pop_front();
          else dq.pop_back();
        }
      }
    }

    if (errored) continue;
    cout << "[";
    if (!dq.empty()) {
      if (reversed) {
        cout << dq.back();
        dq.pop_back();
        while (!dq.empty()) {
          cout << "," << dq.back();
          dq.pop_back();
        }
      }else {
        cout << dq.front();
        dq.pop_front();
        while (!dq.empty()) {
          cout << "," << dq.front();
          dq.pop_front();
        }
      }
    }
    cout << "]\n";
  }

  return 0;
}
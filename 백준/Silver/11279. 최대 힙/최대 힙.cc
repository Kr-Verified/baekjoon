#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, input;
  cin >> n;
  priority_queue<int> pq;
  for (int i = 0; i < n; i++) {
    cin >> input;
    if (input == 0) {
      if (!pq.empty()) {
        cout << pq.top() << '\n';
        pq.pop();
      }else cout << "0\n";
    }else {
      pq.push(input);
    }
  }

  return 0;
}
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int n, a, b;
  cin >> n;
  
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    cout << "yes\n";
  }
  
  return 0;
}
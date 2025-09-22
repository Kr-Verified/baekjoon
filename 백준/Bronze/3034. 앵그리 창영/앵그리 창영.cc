#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, w, h, length;
  cin >> n >> w >> h;
  for (int i = 0; i < n; i++) {
    cin >> length;
    cout << (length*length <= w*w + h*h ? "DA" : "NE") << '\n';
  }

  return 0;
}
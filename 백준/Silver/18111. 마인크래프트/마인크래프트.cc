#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m, b, input, result = 1000000000, height;
  cin >> n >> m >> b;

  vector<vector<int>> field(n, vector<int>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> input;
      field[i][j] = input;
    }
  }

  for (int h = 256; h >= 0; h--) {
    int temp = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (field[i][j] < h) temp += h - field[i][j];
        else if (field[i][j] > h) temp += 2 * (field[i][j] - h);
        cnt += h - field[i][j];
      }
    }
    if (cnt > b) continue;
    if (temp < result)
    {
      result = temp;
      height = h;
    }
  }

  cout << result << " " << height << '\n';
  return 0;
}
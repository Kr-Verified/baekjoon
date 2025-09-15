#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int repair(vector<vector<char>> &field, int start_x, int start_y, char start_color) {
  int count = 0;
  char colors[2] = {start_color, (start_color=='W'?'B':'W')};
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (field[start_x + i][start_y + j] != colors[(i + j) % 2]) count++;
    }
  }
  return count;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m, result = 64;
  cin >> n >> m;
  vector<vector<char>> field(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    string row;
    cin >> row;
    for (int j = 0; j < m; j++) field[i][j] = row[j];
  }

  for (int i = 0; i <= n - 8; i++) {
    for (int j = 0; j <= m - 8; j++) {
      int W = repair(field, i, j, 'W');
      int B = repair(field, i, j, 'B');
      result = min({result, W, B});
    }
  }

  cout << result << '\n';

  return 0;
}
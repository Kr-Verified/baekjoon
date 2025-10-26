#include <iostream>
#include <vector>

using namespace std;

const int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int dfs(vector<vector<int>> &field, int x, int y, int prex, int prey, int depth, int n, int m) {
  if (depth == 3) return field[x][y];
  int tmp = 0, max = 0;
  for (int i = 0; i < 4; i++) {
    int dx = d[i][0]+x, dy = d[i][1]+y;
    if (!(dx < 0 || dy < 0 || dx >= n || dy >= m || (dx == prex && dy == prey))) {
      tmp = dfs(field, dx, dy, x, y, depth + 1, n, m) + field[x][y];
      if (tmp > max) max = tmp;
    }
  }
  return max;
}

int makeShape(vector<vector<int>> &field, int x, int y, int n, int m) {
  int max = 0;
  if (x - 1 >= 0 && y - 1 >= 0 && y + 1 < m) {
    int tmp = field[x - 1][y] + field[x][y - 1] + field[x][y] + field[x][y + 1];
    if (tmp > max) max = tmp;
  }
  if (x + 1 < n && y - 1 >= 0 && y + 1 < m) {
    int tmp = field[x][y - 1] + field[x][y] + field[x][y + 1] + field[x + 1][y];
    if (tmp > max) max = tmp;
  }
  if (x - 1 >= 0 && x + 1 < n && y - 1 >= 0) {
    int tmp = field[x - 1][y] + field[x][y - 1] + field[x][y] + field[x + 1][y];
    if (tmp > max) max = tmp;
  }
  if (x - 1 >= 0 && x + 1 < n && y + 1 < m) {
    int tmp = field[x - 1][y] + field[x][y] + field[x][y + 1] + field[x + 1][y];
    if (tmp > max) max = tmp;
  }
  return max;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> v(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> v[i][j];
  }

  int max = 0, tmp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      tmp = dfs(v, i, j, -1, -1, 0, n, m);
      if (tmp > max) max = tmp;
      tmp = makeShape(v, i, j, n, m);
      if (tmp > max) max = tmp;
    }
  }

  cout << max << endl;
  return 0;
}
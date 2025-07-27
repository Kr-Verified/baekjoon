#include <stdio.h>

int visited[100][100], key[26], get[100][100] = {0};
char field[100][100];
int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int bfs(int r, int c, int x, int y, int* changed) {
  int queue[10000][2], front=0, rear=0, cnt=0;
  queue[rear][0] = x;
  queue[rear][1] = y;
  while (front <= rear) {
    int x = queue[front][0];
    int y = queue[front++][1];
    char ch = field[x][y];
    if (ch == '$' && get[x][y] == 0) {
      cnt++;
      get[x][y] = 1;
    }
    if (ch >= 'a' && ch <= 'z' && key[ch - 'a'] == 0) {
      key[ch - 'a']++;
      *changed = 1;
    }
    if (ch >= 'A' && ch <= 'Z' && key[ch - 'A'] == 0) continue;
    for (int i = 0; i < 4; i++) {
      int dx = x + d[i][0];
      int dy = y + d[i][1];
      if (visited[dx][dy]) continue;
      char ch = field[dx][dy];
      if (ch == '*') continue;
      if (dx < 0 || dx >= r || dy < 0 || dy >= c) continue;

      if (ch == '.' || ch == '$' || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z' && key[ch - 'A'])) {
        queue[++rear][0] = dx;
        queue[rear][1] = dy;
        visited[dx][dy] = 1;
      }
    }
  }
  return cnt;
}

int main(void) {
  int t, r, c;
  char temp[26];
  scanf("%d", &t);
  for (int k = 0; k < t; k++) {
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) scanf("%s", field[i]);

    for (int i = 0; i < 26; i++) key[i] = 0;
    scanf("%s", temp);
    int temp_idx = 0;
    while (temp[temp_idx] != '\0') key[temp[temp_idx++]-'a']++;
    int sum = 0;
    int changed = 1;
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) get[i][j] = 0;
    while (changed) {
      changed = 0;
      for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) visited[i][j] = 0;
      for (int i = 0; i < c; i++) {
        if (field[0][i] != '*' && !visited[0][i]) {
          visited[0][i] = 1;
          sum += bfs(r, c, 0, i, &changed);
        }
        if (field[r-1][i] != '*' && !visited[r-1][i]) {
          visited[r-1][i] = 1;
          sum += bfs(r, c, r-1, i, &changed);
        }
      }
      for (int i = 0; i < r; i++) {
        if (field[i][0] != '*' && !visited[i][0]) {
          visited[i][0] = 1;
          sum += bfs(r, c, i, 0, &changed);
        }
        if (field[i][c-1] != '*' && !visited[i][c-1]) {
          visited[i][c-1] = 1;
          sum += bfs(r, c, i, c-1, &changed);
        }
      }
    }
    printf("%d\n", sum);
  }
  return 0;
}
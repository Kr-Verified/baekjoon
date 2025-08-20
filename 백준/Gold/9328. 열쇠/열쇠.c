#include <stdio.h>
#include <string.h>

int visited[100][100], get[100][100], key[26];
char field[100][100];
int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int bfs(int r, int c, int x, int y, int *changed) {
  int queue[10000][2], front = 0, rear = 0, cnt = 0;
  queue[rear][0] = x;
  queue[rear][1] = y;
  while (front <= rear) {
    int dx = queue[front][0];
    int dy = queue[front++][1];
    char ch = field[dx][dy];
    if (ch == '$' && !get[dx][dy]) {
      cnt++;
      get[dx][dy] = 1;
    }
    if (ch >= 'a' && ch <= 'z' && !key[ch-'a']) {
      key[ch-'a'] = 1;
      *changed = 1;
    }
    if (ch >= 'A' && ch <= 'Z' && !key[ch-'A']) continue;

    for (int i = 0; i < 4; i++) {
      int ddx = dx + d[i][0];
      int ddy = dy + d[i][1];

      if (ddx < 0 || ddx >= r || ddy < 0 || ddy >= c) continue;
      char mch = field[ddx][ddy];
      if (mch == '*' || visited[ddx][ddy]) continue;
      if (mch >= 'A' && mch <= 'Z' && !key[mch-'A']) continue;
      queue[++rear][0] = ddx;
      queue[rear][1] = ddy;
      visited[ddx][ddy] = 1;
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
    scanf("%s",temp);
    if (strcmp(temp, "0") != 0) {
      int temp_idx = 0;
      while (temp[temp_idx] != '\0') key[temp[temp_idx++]-'a']++;
    }
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) get[i][j] = 0;
    int sum = 0;
    int changed = 1;
    while (changed) {
      changed = 0;
      for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) visited[i][j] = 0;

      for (int i = 0; i < r; i++) {
        char ch = field[i][0];
        if (ch != '*' && !visited[i][0]) {
          visited[i][0] = 1;
          sum += bfs(r, c, i, 0, &changed);
        }
        ch = field[i][c-1];
        if (ch != '*' && !visited[i][c-1]) {
          visited[i][c-1] = 1;
          sum += bfs(r, c, i, c-1, &changed);
        }
      }
      for (int i = 0; i < c; i++) {
        char ch = field[0][i];
        if (ch != '*' && !visited[0][i]) {
          visited[0][i] = 1;
          sum += bfs(r, c, 0, i, &changed);
        }
        ch = field[r-1][i];
        if (ch != '*' && !visited[r-1][i]) {
          visited[r-1][i] = 1;
          sum += bfs(r, c, r-1, i, &changed);
        }
      }
    }
    printf("%d\n", sum);
  }

  return 0;
}
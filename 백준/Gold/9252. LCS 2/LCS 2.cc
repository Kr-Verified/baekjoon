#include <stdio.h>

int dp[1001][1001] = {0};

int main(void) {
  char a[1001], b[1001], common[1000];
  int al=0, bl=0, cl=0;
  scanf("%s", a);
  scanf("%s", b);

  while (a[al] != '\0') al++;
  while (b[bl] != '\0') bl++;

  for (int i = 0; i < al; i++) {
    for (int j = 0; j < bl; j++) {
      if (a[i] == b[j]) {
        dp[i+1][j+1] = dp[i][j] + 1;
      } else dp[i+1][j+1] = dp[i+1][j]>dp[i][j+1]?dp[i+1][j]:dp[i][j+1];
    }
  }

  printf("%d\n", dp[al][bl]);
  if (dp[al][bl]!=0) {
    int x = al, y = bl;
    while (dp[x][y]!=0) {
      if (a[x-1] == b[y-1]) {
        common[cl++] = a[x-1];
        x--;
        y--;
      }else {
        if (dp[x-1][y]>dp[x][y-1]) x--;
        else y--;
      }
    }
    for (int i = cl-1; i >= 0; i--) printf("%c", common[i]);
  }

  return 0;
}
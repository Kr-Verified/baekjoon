#include <stdio.h>

int field[750][750];
int dp[750][750][4]={0};

int main(void) {
  int r, c;
  scanf("%d %d", &r, &c);
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      scanf("%1d", &field[i][j]);
    }
  }
  // 좌-상 대각선
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (field[i][j] == 1) {
        if (i==0 || j==0) dp[i][j][0] = 1;
        else dp[i][j][0] = dp[i-1][j-1][0]+1;
      }
    }
  }
  // 좌-하 대각선
  for (int i = r-1; i >= 0; i--) {
    for (int j = 0; j < c; j++) {
      if (field[i][j] == 1) {
        if (i==r-1 || j==0) dp[i][j][1] = 1;
        else dp[i][j][1] = dp[i+1][j-1][1]+1;
      }
    }
  }
  // 우-하 대각선
  for (int i = r-1; i >= 0; i--) {
    for (int j = c-1; j >= 0; j--) {
      if (field[i][j] == 1) {
        if (i==r-1 || j==c-1) dp[i][j][2] = 1;
        else dp[i][j][2] = dp[i+1][j+1][2]+1;
      }
    }
  }
  // 우-상 대각선
  for (int i = 0; i < r; i++) {
    for (int j = c-1; j >= 0; j--) {
      if (field[i][j] == 1) {
        if (i==0 || j==c-1) dp[i][j][3] = 1;
        else dp[i][j][3] = dp[i-1][j+1][3]+1;
      }
    }
  }

  // 찾기
  int max = 0, m;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      m = dp[i][j][1]<dp[i][j][2]?dp[i][j][1]:dp[i][j][2];
      for (int k = 1; k <= m; k++) {
        if (i+2*(k-1)<r && field[i+2*(k-1)][j] && dp[i+2*(k-1)][j][0]>=k&&dp[i+2*(k-1)][j][3]>=k) {
          if (max < k) max = k;
        }
      }
      m = dp[i][j][2]<dp[i][j][3]?dp[i][j][2]:dp[i][j][3];
      for (int k = 1; k <= m; k++) {
        if (i+2*(k-1)<c && field[i][j+2*(k-1)] && dp[i][j+2*(k-1)][0]>=k&&dp[i][j+2*(k-1)][1]>=k) {
          if (max < k) max = k;
        }
      }
    }
  }
  printf("%d\n", max);
  return 0;
}
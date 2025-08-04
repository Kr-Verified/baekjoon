#include <stdio.h>

long long int dp[500][500] = {0};

int main() {
  int n, temp;
  scanf("%d", &n);

  int matrix[501] = {0};

  scanf("%d %d", &matrix[0], &matrix[1]);
  for (int i = 2; i < n+1; i++) scanf("%d %d", &temp, &matrix[i]);
  for (int len = 2; len <= n; len++) {
    for (int i = 0; i+len-1 < n; i++) {
      int j = i+len-1;
      for (int k = i; k < j; k++) {
        temp = dp[i][k] + dp[k+1][j] + matrix[i]*matrix[k+1]*matrix[j+1];
        if (dp[i][j] == 0 || dp[i][j] > temp) dp[i][j] = temp;
      }
    }
  }


  printf("%lld\n", dp[0][n-1]);
}
#include <stdio.h>

int dp[2000][2000] = {0};

int main() {
  int n, m, arr[2000], s, e;
  scanf("%d",&n);
  for (int i = 0; i < n; i++) scanf("%d",&arr[i]);

  for (int i = 0; i < n; i++) dp[i][i] = 1;
  for (int i = 0; i < n-1; i++) dp[i][i+1] = arr[i]==arr[i+1];
  for (int len = 3; len <= n; len++) for (int i = 0; i+len-1 < n; i++) {
    dp[i][i+len-1] = dp[i+1][i+len-2] && (arr[i]==arr[i+len-1]);
  }
  
  scanf("%d",&m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d",&s,&e);
    printf("%d\n", dp[s-1][e-1]);
  }

  return 0;
}
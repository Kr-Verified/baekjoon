#include <stdio.h>

int main(void) {
  int T, K, files[500], dp[501]={0};
  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    int minCost[500][500]={0};
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
      scanf("%d", &files[i]);
      dp[i+1] = files[i]+dp[i];
    }

    for (int len = 2; len <= K; len++) {
      for (int i = 0; i+len-1 < K; i++) {
        int j = i+len-1;
        for (int k = i; k < j; k++) {
          int temp = minCost[i][k] + minCost[k+1][j] + dp[j+1]-dp[i];
          if (minCost[i][j]==0 || minCost[i][j] > temp) minCost[i][j] = temp;
        }
      }
    }
    printf("%d\n", minCost[0][K-1]);
  }

  return 0;
}
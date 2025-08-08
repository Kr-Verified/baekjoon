#include <stdio.h>

int main(void) {
  int n, s, arr[100000], dp[100001]={0}, left=1, right=1, minLen=100001, len;
  scanf("%d %d", &n, &s);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    dp[i+1] = arr[i]+dp[i];
  }

  while (left <= right && right <= n) {
    int val = dp[right] - dp[left-1];
    if (val < s) right++;
    else {
      len = right - left + 1;
      if (minLen > len) minLen = len;
      left++;
    }
  }

  printf("%d\n", minLen==100001 ? 0 : minLen);

  return 0;
}
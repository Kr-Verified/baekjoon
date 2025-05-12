n = int(input())
dp = [1, 1, 1] + [0]*97
idx = 3
for _ in range(n):
  test = int(input())
  if dp[test-1]==0:
    for i in range(idx, test):
      dp[i] = dp[i-2]+dp[i-3]
  print(dp[test-1])
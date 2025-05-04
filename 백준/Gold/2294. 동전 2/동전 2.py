n, k = map(int, input().split())
coins = [int(input()) for _ in range(n)]
dp = [[10001, 0] for _ in range(max(n, k+1))]
dp[0][0] = 0
coins.sort()

for i in range(coins[0], k+1):
  for coin in coins:
    if i-coin>=0 and dp[i][0]>dp[i-coin][0]+1:
      dp[i][0] = dp[i-coin][0]+1
      dp[i][1] = i-coin

print(dp[k][0] if dp[k][0]!=10001 else -1)
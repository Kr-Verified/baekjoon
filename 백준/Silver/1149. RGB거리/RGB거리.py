n = int(input())
price = [list(map(int, input().split())) for _ in range(n)]
dp = [[0, 0, 0] for _ in range(n)]

for i in range(n):
  dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + price[i][0]
  dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + price[i][1]
  dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + price[i][2]

print(min(dp[n-1]))
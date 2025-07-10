n = int(input())
dp = [float('inf')]*(n+5)
dp[3] = 1
dp[5] = 1
for i in range(6, n+1):
  if dp[i]>dp[i-3]+1:
    dp[i] = dp[i-3]+1
  if dp[i]>dp[i-5]+1:
    dp[i] = dp[i-5]+1

print(-1 if dp[n]==float('inf') else dp[n])
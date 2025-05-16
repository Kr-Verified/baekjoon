dp = [0]*12
dp[0], dp[1], dp[2] = 1, 1, 2

for _ in range(int(input())):
  n = int(input())
  for i in range(3, n+1):
    dp[i] = dp[i-1]+dp[i-2]+dp[i-3]
  print(dp[n])
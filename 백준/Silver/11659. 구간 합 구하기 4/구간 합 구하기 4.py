import sys
sysInput = sys.stdin.readline

n, m = map(int, sysInput().split())
nums = list(map(int, sysInput().split()))

dp = [0]
for i in range(n):
  dp.append(dp[i]+nums[i])

for _ in range(m):
  i, j = map(int, sysInput().split())
  print(dp[j]-dp[i-1])
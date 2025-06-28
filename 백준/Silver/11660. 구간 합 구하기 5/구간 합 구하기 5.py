import sys
input = sys.stdin.readline

n, m = map(int, input().split())

nums = []
for i in range(n):
  nums.append(list(map(int, input().split())))

dp = [[0]*(n+1) for _ in range(n+1)]
for i in range(1, n+1):
  dp[1][i] = nums[0][i-1]+dp[1][i-1]

for col in range(1, n+1):
  for row in range(2, n+1):
    dp[row][col]=dp[row-1][col]+dp[row][col-1]+nums[row-1][col-1]-dp[row-1][col-1]

for _ in range(m):
  fx, fy, tx, ty = map(int, input().split())
  print(dp[tx][ty]-dp[fx-1][ty]-(dp[tx][fy-1]-dp[fx-1][fy-1]))
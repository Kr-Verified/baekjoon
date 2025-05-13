n = int(input())
nums = []
nums.append([int(input())])
dp = [[0 for _ in range(i+1)] for i in range(n)]
dp[0][0] = nums[0][0]

for i in range(1, n):
  nums.append(list(map(int, input().split())))
  for j in range(i+1):
    if j==0:
      dp[i][j] = dp[i-1][j]+nums[i][j]
    elif j==i:
      dp[i][j] = dp[i-1][j-1]+nums[i][j]
    else:
      dp[i][j] = nums[i][j]+ max(dp[i-1][j-1], dp[i-1][j])

print(max(dp[n-1]))
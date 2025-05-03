n = int(input())
dp = [[100000, 0] for _ in range(max(4, n+1))]
dp[0][0], dp[1][0], dp[2], dp[3] = 0, 0, [1, 1], [1, 1]

for i in range(2, n+1):
  if dp[i][0]>dp[i-1][0]+1:
    dp[i][0]=dp[i-1][0]+1
    dp[i][1]=i-1
  if i%2==0 and dp[i][0]>dp[i//2][0]+1:
    dp[i][0]=dp[i//2][0]+1
    dp[i][1]=i//2
  if i%3==0 and dp[i][0]>dp[i//3][0]+1:
    dp[i][0]=dp[i//3][0]+1
    dp[i][1]=i//3

print(dp[n][0])
while n!=0:
  print(n, end=' ')
  n = dp[n][1]
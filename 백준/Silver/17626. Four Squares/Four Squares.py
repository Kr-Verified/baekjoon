import math
n = int(input())
dp = [i for i in range(n+1)]
sqaure = [i*i for i in range(min(250, math.floor(n**0.5)+1))]

for i in range(1, n+1):
  for sq in sqaure:
    if sq>i:
      break
    dp[i] = min(dp[i], dp[i-sq]+1)

print(dp[n])
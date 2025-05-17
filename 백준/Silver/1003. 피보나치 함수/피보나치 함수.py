def f(n):
  if dp[n]!=(0, 0):
    return dp[n]
  pp = f(n-2)
  p = f(n-1)
  dp[n] = (p[0]+pp[0], p[1]+pp[1])
  return dp[n]

dp = [(0, 0) for _ in range(41)]
dp[0], dp[1] = (1, 0), (0, 1)
for _ in range(int(input())):
  n = int(input())
  print(*f(n))
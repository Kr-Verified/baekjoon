import sys
input = sys.stdin.readline

n = int(input())
scores = [int(input()) for _ in range(n)]
for _ in range(2):
  scores.append(0)
dp = [0]*max(3, n)
dp[0] = scores[0]
dp[1] = scores[0]+scores[1]
dp[2] = max(scores[0]+scores[2], scores[1]+scores[2])
if n>=3:
  for i in range(3, n):
    dp[i] = max(dp[i-2]+scores[i], dp[i-3]+scores[i-1]+scores[i])

print(dp[n-1])
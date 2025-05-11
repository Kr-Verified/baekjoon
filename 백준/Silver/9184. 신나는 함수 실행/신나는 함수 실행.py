dp = [[[0 for _ in range(101)] for _ in range(101)] for _ in range(101)]

def w(a, b, c):
  if a<=0 or b<=0 or c<=0:
    return 1
  if a>20 or b>20 or c>20:
    return w(20, 20, 20)
  if dp[a+50][b+50][c+50]!=0:
    return dp[a+50][b+50][c+50]
  if a<b and b<c:
    dp[a+50][b+50][c+50] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
    return dp[a+50][b+50][c+50]
  dp[a+50][b+50][c+50] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
  return dp[a+50][b+50][c+50]

while True:
  a, b, c = map(int, input().split())
  if a==b==c==-1:
    break
  print(f'w({a}, {b}, {c}) =', w(a, b, c))

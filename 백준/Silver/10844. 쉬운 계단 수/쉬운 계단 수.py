n = int(input())
stairs = [[0]*10 for _ in range(n+1)]

for i in range(1, 10):
  stairs[1][i] = 1

for i in range(2, n+1):
  for j in range(10):
    if j==0:
      stairs[i][j] = stairs[i-1][1]
    elif j==9:
      stairs[i][j] = stairs[i-1][8]
    else:
      stairs[i][j] = stairs[i-1][j-1]+stairs[i-1][j+1]
    stairs[i][j]%=1000000000

print(sum(stairs[n])%1000000000)
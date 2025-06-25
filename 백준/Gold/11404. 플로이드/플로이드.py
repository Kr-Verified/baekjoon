n = int(input())
m = int(input())
cost = [[1000000000 for _ in range(n+1)] for _ in range(n+1)]
for _ in range(m):
  a, b, c = map(int, input().split())
  cost[a][b] = min(cost[a][b], c)

for k in range(1, n+1):
  for i in range(1, n+1):
    for j in range(1, n+1):
      if i==j: cost[i][j]=0
      cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j])

for row in cost[1:]:
  for i in row[1:]:
    print(0 if i==1000000000 else i, end=' ')
  print()
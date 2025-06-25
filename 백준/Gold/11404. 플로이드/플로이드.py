import sys
input = sys.stdin.readline

n = int(input())
m = int(input())
cost = [[float('inf') for _ in range(n+1)] for _ in range(n+1)]

for i in range(n+1):
  cost[i][i] = 0

for _ in range(m):
  a, b, c = map(int, input().split())
  cost[a][b] = min(cost[a][b], c)

for k in range(1, n+1):
  for i in range(1, n+1):
    for j in range(1, n+1):
      cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j])

for row in cost[1:]:
  for i in row[1:]:
    sys.stdout.write('0 ' if i==float('inf') else str(i) + ' ')
  sys.stdout.write('\n')
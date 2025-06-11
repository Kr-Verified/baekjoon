import sys
input = sys.stdin.readline

n = int(input())
equations = []
for _ in range(n):
  equations.append(list(map(int, input().split())))

for i in range(n-1):
  row_maxI = max(range(i, n), key=lambda r: abs(equations[r][i]))
  equations[i], equations[row_maxI] = equations[row_maxI], equations[i]

  pivot = equations[i][i]
  for k in range(i+1, n):
    factor = equations[k][i]
    for j in range(n+1):
      equations[k][j]=equations[k][j]*pivot-equations[i][j]*factor

result = [0] * n
for i in range(n - 1, -1, -1):
    value = equations[i][n]
    for j in range(i + 1, n):
        value -= equations[i][j] * result[j]
    result[i] = value // equations[i][i]

print(*result)
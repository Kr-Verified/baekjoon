houses = []
n = int(input())
for _ in range(n):
  houses.append(list(map(int, list(input()))))

d = [(-1, 0), (1, 0), (0, -1), (0, 1)]
def bfs(x, y):
  global size
  for dx, dy in d:
    nx, ny = x+dx, y+dy
    if 0<=nx<n and 0<=ny<n and houses[nx][ny]==1 and not visited[nx][ny]:
      visited[nx][ny] = True
      houses[nx][ny] = 2
      size+=1
      bfs(nx, ny)

visited = [[False for _ in range(n)] for _ in range(n)]
sizes = []
cnt = 2
for x in range(n):
  for y in range(n):
    if houses[x][y]==1 and not visited[x][y]:
      houses[x][y] = cnt
      visited[x][y] = True
      size = 1
      bfs(x, y)
      sizes.append(size)
      cnt+=1
print(cnt-2)
for num in sorted(sizes):
  print(num)
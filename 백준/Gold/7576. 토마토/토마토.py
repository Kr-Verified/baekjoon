from collections import deque

m, n = map(int, input().split())
tomatoes = [list(map(int, input().split())) for _ in range(n)]
time = 0
dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]

queue = deque()
for x in range(n):
  for y in range(m):
    if tomatoes[x][y]==1:
      queue.append((x, y, time))

while queue:
  x, y, t = queue.popleft()
  if t>time:
    time = t

  for i in range(4):
    nx, ny = x+dx[i], y+dy[i]
    if 0<=nx<n and 0<=ny<m and tomatoes[nx][ny]==0:
      queue.append((nx, ny, t+1))
      tomatoes[nx][ny] = 1

for row in tomatoes:
  if 0 in row:
    print(-1)
    break
else:
  print(time)
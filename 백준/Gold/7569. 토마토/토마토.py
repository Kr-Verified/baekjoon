from collections import deque

m, n, h = map(int, input().split())
tomatoes = [[list(map(int, input().split())) for _ in range(n)] for _ in range(h)]
time = 0
d = [(-1, 0, 0), (1, 0, 0), (0, -1, 0), (0, 1, 0), (0, 0, -1), (0, 0, 1)]

queue = deque()
for z in range(h):
  for x in range(n):
    for y in range(m):
      if tomatoes[z][x][y]==1:
        queue.append((z, x, y, time))

while queue:
  z, x, y, t = queue.popleft()
  if t>time:
    time = t

  for dx, dy, dz in d:
    nx, ny, nz = x+dx, y+dy, z+dz
    if 0<=nx<n and 0<=ny<m and 0<=nz<h and tomatoes[nz][nx][ny]==0:
      queue.append((nz, nx, ny, t+1))
      tomatoes[nz][nx][ny] = 1

check = True
for floor in tomatoes:
  for row in floor:
    if 0 in row:
      check=False
      print(-1)
      break
  if not check:
    break
if check:
  print(time)
import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
colors = [list(input()) for _ in range(n)]
nCnt, bCnt = 0, 0

def bfs(rx, ry, visited, b):
  queue = deque()
  queue.append((rx, ry))
  visited[rx][ry] = True
  rColor = colors[rx][ry]
  while queue:
    x, y = queue.popleft()
    for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
      nx, ny = x+dx, y+dy
      if 0<=nx<n and 0<=ny<n and not visited[nx][ny]:
        nextColor = colors[nx][ny]
        if b:
          if (rColor != 'B' and nextColor != 'B') or rColor==nextColor:
            visited[nx][ny] = True
            queue.append((nx, ny))
        else:
          if rColor==nextColor:
            visited[nx][ny] = True
            queue.append((nx, ny))

nVisited = [[False for _ in range(n)] for _ in range(n)]
bVisited = [[False for _ in range(n)] for _ in range(n)]
for x in range(n):
  for y in range(n):
    if not nVisited[x][y]:
      nCnt+=1
      bfs(x, y, nVisited, False)
    if not bVisited[x][y]:
      bCnt+=1
      bfs(x, y, bVisited, True)

print(nCnt, bCnt)
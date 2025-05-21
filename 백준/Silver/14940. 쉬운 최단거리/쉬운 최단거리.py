from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
visited = [[False for _ in range(m)] for _ in range(n)]
maps = []
x, y = 0, 0
checked = False
for i in range(n):
  temp = list(map(int, input().split()))
  if not checked:
    for j in range(m):
      if temp[j]==2:
        x, y = i, j
        checked = True
        break
  maps.append(temp)

queue = deque()
queue.append((x, y, 0))
maps[x][y] = 0
visited[x][y] = True
d = [(-1, 0), (1, 0), (0, -1), (0, 1)]
while queue:
  x, y, t = queue.popleft()
  for dx, dy in d:
    if 0<=x+dx<n and 0<=y+dy<m and not visited[x+dx][y+dy] and maps[x+dx][y+dy]!=0:
      maps[x+dx][y+dy] = t+1
      visited[x+dx][y+dy] = True
      queue.append((x+dx, y+dy, t+1))

for i in range(n):
  for j in range(m):
    if not visited[i][j] and maps[i][j]==1:
      maps[i][j] = -1

for row in maps:
  print(* row)
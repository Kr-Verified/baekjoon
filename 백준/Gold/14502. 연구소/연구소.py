import sys
from collections import deque
input = sys.stdin.readline

def wall(cnt, idx):
  global visited, r, c, max_cnt
  if cnt == 3:
    visited = [[False for _ in range(c)] for _ in range(r)]
    temp = [row[:] for row in field]
    count = 0
    for dx, dy in positions:
      bfs(temp, dx, dy)
    for row in temp:
      count += row.count(0)
    max_cnt = max(max_cnt, count)
  else:
    for jdx in range(idx, r*c):
        i, j = divmod(jdx, c)
        if field[i][j] == 0:
          field[i][j] = 1
          wall(cnt + 1, jdx + 1)
          field[i][j] = 0

def bfs(temp, start_x, start_y):
  queue = deque()
  queue.append((start_x, start_y))
  visited[start_x][start_y] = True
  
  while queue:
    node_x, node_y = queue.popleft()
    for x, y in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
      nx, ny = node_x + x, node_y + y
      if 0 <= nx < r and 0 <= ny < c and not visited[nx][ny] and temp[nx][ny] == 0:
        visited[nx][ny] = True
        temp[nx][ny] = 2
        queue.append((nx, ny))

r, c = map(int, input().split())
field = [list(map(int, input().split())) for _ in range(r)]
visited = [[False for _ in range(c)] for _ in range(r)]
positions = [(i, j) for i in range(r) for j in range(c) if field[i][j] == 2]
max_cnt = 0
wall(0, 0)
print(max_cnt)
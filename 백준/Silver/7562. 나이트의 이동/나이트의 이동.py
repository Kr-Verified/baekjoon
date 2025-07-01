import sys
from collections import deque
input = sys.stdin.readline

for _ in range(int(input())):
  size = int(input())
  visited = [[10000 for _ in range(size)] for _ in range(size)]
  fx, fy = map(int, input().split())
  tx, ty = map(int, input().split())
  queue = deque([(fx, fy)])
  visited[fx][fy] = 0
  while queue:
    x, y = queue.popleft()
    if x==tx and y==ty:
      print(visited[x][y])
      break
    for dx, dy in [(-2, -1), (-1, -2), (1, -2), (2, -1), (2, 1), (1, 2), (-1, 2), (-2, 1)]:
      nx, ny = x+dx, y+dy
      if 0<=nx<size and 0<=ny<size and visited[nx][ny]>visited[x][y]+1:
        visited[nx][ny] = visited[x][y]+1
        queue.append((nx, ny))

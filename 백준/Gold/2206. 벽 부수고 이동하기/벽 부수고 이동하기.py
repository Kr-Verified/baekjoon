from collections import deque

n, m = map(int, input().split())
field = [list(map(int, list(input()))) for _ in range(n)]
queue = deque([(0, 0, 1, True)])
visited = [[False for _ in range(m)] for _ in range(n)]
crushVisited = [[False for _ in range(m)] for _ in range(n)]

while queue:
  x, y, d, c = queue.popleft()
  if field[x][y] == 1 and not c:
    continue
  elif field[x][y] == 1 and c:
    c = False

  if x==n-1 and y==m-1:
    print(d)
    exit()
  
  for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
    nx, ny = dx+x, dy+y
    if c:
      if 0 <= nx < n and 0 <= ny < m and not visited[nx][ny]:
        visited[nx][ny] = True
        queue.append((nx, ny, d+1, c))
    else:
      if 0 <= nx < n and 0 <= ny < m and not crushVisited[nx][ny]:
        crushVisited[nx][ny] = True
        queue.append((nx, ny, d+1, c))
  
print(-1)
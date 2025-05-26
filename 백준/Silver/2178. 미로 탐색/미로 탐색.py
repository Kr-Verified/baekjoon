from collections import deque

n, m = map(int, input().split())
maze = [list(map(int, list(input()))) for _ in range(n)]
visited = [[False for _ in range(m)] for _ in range(n)]

queue = deque()
queue.append((0, 0, 1))
visited[0][0] = True


d = [(-1, 0), (1, 0), (0, -1), (0, 1)]
while queue:
  x, y, t = queue.popleft()
  if x==n-1 and y==m-1:
    print(t)
  for dx, dy in d:
    nx, ny = x+dx, y+dy
    if 0<=nx<n and 0<=ny<m and not visited[nx][ny] and maze[nx][ny]==1:
      visited[nx][ny] = True
      queue.append((nx, ny, t+1))
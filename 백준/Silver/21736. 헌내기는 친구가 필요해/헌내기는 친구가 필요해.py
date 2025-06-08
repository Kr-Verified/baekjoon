from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
visited = [[False for _ in range(m)] for _ in range(n)]
maps = []
x, y = 0, 0
for i in range(n):
  temp = list(input())
  maps.append(temp)
  if 'I' in temp:
    x = i
    for j in range(m):
      if temp[j]=='I':
        y = j

queue = deque([(x, y)])
count = 0
while queue:
  x, y = queue.popleft()
  if maps[x][y]=='P':
    count+=1
  for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
    nx, ny = x+dx, y+dy
    if 0<=nx<n and 0<=ny<m and not visited[nx][ny] and maps[nx][ny]!='X':
      visited[nx][ny] = True
      queue.append((nx, ny))

print('TT' if count==0 else count)
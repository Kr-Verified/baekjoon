import sys
input = sys.stdin.readline
sys.setrecursionlimit(3000)
visited = [[False for _ in range(51)] for _ in range(51)]
field = [[0 for _ in range(51)] for _ in range(51)]
def dfs(x, y):
  visited[x][y] = True
  for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
    if 0<=x+dx<len(field) and 0<=y+dy<len(field[0]) and field[x+dx][y+dy]==1 and not visited[x+dx][y+dy]:
      dfs(x+dx, y+dy)

for _ in range(int(input())):
  m, n, k = map(int, input().split())
  field = [[0 for _ in range(m+1)] for _ in range(n+1)]
  visited = [[0 for _ in range(m+1)] for _ in range(n+1)]
  cnt = 0
  # 입력
  for _ in range(k):
    y, x = map(int, input().split())
    field[x][y] = 1
  
  #dfs
  for x in range(n):
    for y in range(m):
      if field[x][y]==1 and not visited[x][y]:
        cnt+=1
        dfs(x, y)
  
  print(cnt)
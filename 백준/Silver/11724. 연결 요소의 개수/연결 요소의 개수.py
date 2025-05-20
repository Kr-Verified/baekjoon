import sys
input = sys.stdin.readline

n, m = map(int, input().split())
graph = {i: [] for i in range(1, n+1)}
visited = [False for _ in range(n+1)]

for _ in range(m):
  a, b = map(int, input().split())
  graph[a].append(b)
  graph[b].append(a)

def dfs(node):
  stack = [node]
  while stack:
    vertex = stack.pop()
    for connection in graph[vertex]:
      if not visited[connection]:
        visited[connection] = True
        stack.append(connection)

cnt = 0
for i in range(1, n+1):
  if not visited[i]:
    cnt+=1
    dfs(i)

print(cnt)
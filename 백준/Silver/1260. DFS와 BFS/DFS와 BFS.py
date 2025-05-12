from collections import deque

#선언
n, m, v = map(int, input().split())
graph = {i: [] for i in range(1, n+1)}
visited = [False]*(n+1)

#입력
for i in range(m):
  x, y = map(int, input().split())
  graph[x].append(y)
  graph[y].append(x)

for i in range(1, n+1):
  graph[i].sort()

#dfs
sequence = []
def dfs(x):
  sequence.append(x)
  visited[x] = True
  for node in graph[x]:
    if not visited[node]:
      dfs(node)

dfs(v)
print(*sequence)

#bfs
sequence = []
visited = [False]*(n+1)
queue = deque([v])
visited[v] = True
while queue:
  node = queue.popleft()
  sequence.append(node)
  for vertex in graph[node]:
    if not visited[vertex]:
      queue.append(vertex)
      visited[vertex] = True

print(*sequence)
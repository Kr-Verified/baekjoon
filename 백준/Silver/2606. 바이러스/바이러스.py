from collections import deque

n = int(input())
e = int(input())
graph = {i: [] for i in range(1, n+1)}
visited = [False]*(n+1)

# 그래프값 삽입
for _ in range(e):
  a, b = map(int, input().split())
  graph[a].append(b)
  graph[b].append(a) 

cnt = 0
queue = deque([1])
visited[1] = True
while queue:
  node = queue.popleft()
  for vertex in graph[node]:
    if not visited[vertex]:
      queue.append(vertex)
      visited[vertex] = True
      if vertex:
        cnt += 1

print(cnt)
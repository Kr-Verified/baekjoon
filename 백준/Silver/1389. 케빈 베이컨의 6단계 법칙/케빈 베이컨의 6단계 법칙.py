from collections import deque

n, m = map(int, input().split())
graph = {i: [] for i in range(1, n+1)}

for _ in range(m):
  a, b = map(int, input().split())
  graph[a].append(b)
  graph[b].append(a)

answer = [float('inf'), 1]

for i in range(1, n+1):
  queue = deque()
  queue.append((i, 0))
  visited = [False]*(n+1)
  visited[i] = True
  cnt = 0
  while queue:
    node, t = queue.popleft()
    cnt += t
    for vertex in graph[node]:
      if not visited[vertex]:
        queue.append((vertex, t+1))
        visited[vertex] = True
  if cnt< answer[0]:
    answer = [cnt, i]

print(answer[1])
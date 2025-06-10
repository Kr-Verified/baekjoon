from collections import deque
import sys
input = sys.stdin.readline

n = int(input())
f, t = map(int, input().split())
graph = {i:[] for i in range(1, n+1)}
visited = [False]*(n+1)
for _ in range(int(input())):
  x, y = map(int, input().split())
  graph[x].append(y)
  graph[y].append(x)

result = -1
queue = deque([(f, 0)])
while queue:
  node, time = queue.popleft()
  if node==t:
    result = time
    break
  for vertex in graph[node]:
    if not visited[vertex]:
      visited[vertex] = True
      queue.append((vertex, time+1))

print(result)
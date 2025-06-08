from collections import deque
import sys
input = sys.stdin.readline

n = int(input())
graph = {i:[] for i in range(1, n+1)}
visited = [False for _ in range(n+1)]
for _ in range(n-1):
  a, b = map(int, input().split())
  graph[a].append(b)
  graph[b].append(a)

queue = deque([1])
parent = [0]*(n+1)
while queue:
  node = queue.popleft()
  for vertex in graph[node]:
    if not visited[vertex]:
      visited[vertex] = True
      queue.append(vertex)
      parent[vertex] = node
      
for i in parent[2:]:
  print(i)
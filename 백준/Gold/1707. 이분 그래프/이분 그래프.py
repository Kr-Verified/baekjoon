import sys
from collections import deque
input = sys.stdin.readline

for _ in range(int(input())):
  v, e = map(int, input().split())
  graph = {i: [] for i in range(1, v + 1)}
  colors = [-1] * (v + 1)
  is_bipartite = True
  for _ in range(e):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
  for start in range(1, v + 1):
    if colors[start] == -1:
      queue = deque()
      queue.append(start)
      colors[start] = 0
      while queue and is_bipartite:
        node = queue.popleft()
        for next in graph[node]:
          if colors[next] == -1:
            colors[next] = 1- colors[node]
            queue.append(next)
          elif colors[next] == colors[node]:
            is_bipartite = False
            break
    if not is_bipartite:
      break
  print("YES" if is_bipartite else "NO")
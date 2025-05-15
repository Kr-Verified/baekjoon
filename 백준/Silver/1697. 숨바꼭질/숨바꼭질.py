from collections import deque

a, b = map(int, input().split())

bigger = max(a, b)*2+1
queue = deque()
queue.append((a, 0))
visited = set()
while queue:
  node, t = queue.popleft()
  if node == b:
    print(t)
    break
  for vertex in [node+1, node-1, node*2]:
    if vertex not in visited and 0<=vertex<bigger:
      queue.append((vertex, t+1))
      visited.add(vertex)
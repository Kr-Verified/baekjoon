import heapq, sys
input = sys.stdin.readline

vn, e = map(int, input().split())
k = int(input())
graph = {i:[] for i in range(1, vn+1)}
min_weight = [float('inf') for _ in range(vn+1)]
min_weight[k] = 0
for _ in range(e):
  u, v, w = map(int, input().split())
  graph[u].append((w, v))

queue = [(0, k)]
while queue:
  weight, node = heapq.heappop(queue)
  if weight>min_weight[node]:
    continue
  for nw, vertex in graph[node]:
    if min_weight[vertex]>min_weight[node]+nw:
      min_weight[vertex] = min_weight[node]+nw
      heapq.heappush(queue, (min_weight[vertex], vertex))

for i in range(1, vn+1):
  print(min_weight[i] if min_weight[i]!=float('inf') else 'INF')
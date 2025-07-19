import heapq, sys
input = sys.stdin.readline

n, e = map(int, input().split())
graph = {i:[] for i in range(1, n+1)}

for i in range(e):
  a, b, c = map(int, input().split())
  graph[a].append((c, b))
  graph[b].append((c, a))
u, v = map(int, input().split())

def dij(start_cost, start_node, end):
  queue = []
  heapq.heappush(queue, (start_cost, start_node))
  minDistance = [-1 for _ in range(n+1)]
  minDistance[start_node] = start_cost
  while queue:
    cost, node = heapq.heappop(queue)
    for next_cost, next in graph[node]:
      if minDistance[next] == -1 or minDistance[next] > cost + next_cost:
        minDistance[next] = cost + next_cost
        heapq.heappush(queue, (cost+next_cost, next))

  if minDistance[end] == -1:
    print(-1)
    exit()
  return minDistance[end]

r1 = dij(dij(dij(0, 1, u), u, v), v, n)
r2 = dij(dij(dij(0, 1, v), v, u), u, n)
print(min(r1, r2))
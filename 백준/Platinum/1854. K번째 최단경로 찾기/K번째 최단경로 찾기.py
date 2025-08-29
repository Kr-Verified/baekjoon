import heapq, sys
input = sys.stdin.readline

n, m, k = map(int, input().split())

graph = {i : [] for i in range(1, n+1)}

for _ in range(m):
  a, b, c = map(int, input().split())
  graph[a].append((c, b))

queue = [(0, 1)]
dist = [[] for _ in range(n+1)]
heapq.heappush(dist[1], 0)

while queue:
  cost, node = heapq.heappop(queue)
  for next_cost, next in graph[node]:
    sum_cost = cost + next_cost
    if len(dist[next]) < k:
      heapq.heappush(queue, (sum_cost, next))
      heapq.heappush(dist[next], -sum_cost)
    else:
      if -dist[next][0] > sum_cost:
        heapq.heappush(queue, (sum_cost, next))
        heapq.heappop(dist[next])
        heapq.heappush(dist[next], -sum_cost)

for i in range(1, n+1):
  if len(dist[i]) == k:
    print(-dist[i][0])
  else:
    print(-1)
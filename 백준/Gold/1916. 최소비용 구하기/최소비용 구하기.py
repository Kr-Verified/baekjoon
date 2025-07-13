import heapq
n = int(input())
m = int(input())
graph = {i:[] for i in range(1, n+1)}
cost = [float('inf') for _ in range(n+1)]
queue = []

for _ in range(m):
  a, b, c = map(int, input().split())
  graph[a].append((c, b))

f, t = map(int, input().split())

queue = [(0, f)]
cost[f] = 0
while queue:
  current_cost, city = heapq.heappop(queue)
  if city == t:
    print(current_cost)
    break
  for next_cost, next in graph[city]:
    if cost[next] > cost[city] + next_cost:
      cost[next] = cost[city] + next_cost
      heapq.heappush(queue, (current_cost+next_cost, next))
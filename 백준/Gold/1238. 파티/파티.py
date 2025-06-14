import heapq
n, m, x = map(int, input().split())
cities = {i:[] for i in range(1, n+1)}
for _ in range(m):
  f, t, w = map(int, input().split())
  cities[f].append((w, t))

def dijkstra(start):
  queue = [(0, start)]
  max_cost = [float('inf')]*(n+1)
  max_cost[start] = 0
  while queue:
    cost, city = heapq.heappop(queue)
    if max_cost[city]<cost:
      continue
    for weight, next in cities[city]:
      if max_cost[next] > max_cost[city]+weight:
        max_cost[next] = max_cost[city]+weight
        heapq.heappush(queue, (max_cost[next], next))
  return max_cost

max_student = 0
to_students = dijkstra(x)

for student in range(1, n+1):
  from_students = dijkstra(student)
  max_student=max(from_students[x]+to_students[student], max_student)

print(max_student)
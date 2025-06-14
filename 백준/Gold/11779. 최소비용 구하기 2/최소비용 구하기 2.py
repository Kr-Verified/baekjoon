import heapq, sys
input = sys.stdin.readline

n = int(input())
m = int(input())
cities = {i:[] for i in range(1, n+1)}
minCost = [float('inf')]*(n+1)
trace = [-1]*(n+1)
for _ in range(m):
  s, e, w = map(int, input().split())
  cities[s].append((w, e))
start, end = map(int, input().split())
minCost[start] = 0
trace[start] = 0

queue = [(0, start)]
while queue:
  w, city = heapq.heappop(queue)
  if minCost[city]<w:
    continue
  for cost, next in cities[city]:
    if minCost[next] > minCost[city]+cost:
      minCost[next] = minCost[city]+cost
      trace[next] = city
      heapq.heappush(queue, (minCost[next], next))

print(minCost[end])
idx = end
sequence = []
while trace[idx]!=-1:
  sequence.append(idx)
  idx = trace[idx]

print(len(sequence))
sequence.reverse()
print(*sequence)
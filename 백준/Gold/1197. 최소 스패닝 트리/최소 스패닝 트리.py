import sys
input = sys.stdin.readline

def find(x):
  while x != parent[x]:
    parent[x] = parent[parent[x]]
    x = parent[x]
  return x

def union(rootX, rootY):
  x = find(rootX)
  y = find(rootY)
  if x < y:
    parent[y] = x
  else:
    parent[x] = y

v, e = map(int, input().split())
edges = []
parent = list(range(v + 1))
min_cost = 0

for _ in range(e):
  a, b, w = map(int, input().split())
  edges.append((a, b, w))

edges.sort(key=lambda x: x[2])

for a, b, w in edges:
  if find(a) != find(b):
    union(a, b)
    min_cost += w

print(min_cost)
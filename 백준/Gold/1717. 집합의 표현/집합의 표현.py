import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

def find(x):
  if parent[x] < 0:
    return x
  parent[x] = find(parent[x])
  return parent[x]

def union(x, y):
  rootX = find(x)
  rootY = find(y)
  if rootX == rootY: return
  if parent[rootX] < parent[rootY]:
    parent[rootX] += parent[rootY]
    parent[rootY] = rootX
  else:
    parent[rootY] += parent[rootX]
    parent[rootX] = rootY

n, m = map(int, input().split())
parent = [-1] * (n+1)
for _ in range(m):
  t, a, b = map(int, input().split())
  if t == 0:
    union(a, b)
  else:
    if find(a) == find(b):
      print("YES")
    else:
      print("NO")
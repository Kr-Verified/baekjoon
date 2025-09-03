import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**7)

def find(x):
  if parent[x] < 0:
    return x
  parent[x] = find(parent[x])
  return parent[x]

def union(x, y):
  x_root = find(x)
  y_root = find(y)
  if x_root == y_root:
    return
  if parent[x_root] < parent[y_root]:
    parent[x_root] += parent[y_root]
    parent[y_root] = x_root
  else:
    parent[y_root] += parent[x_root]
    parent[x_root] = y_root

def merge(arr):
  for i in range(len(arr)-1):
    union(arr[i], arr[i+1])

n, m = map(int, input().split())
parent = [-1] * (n + 1)
k_n, *knowers = map(int, input().split())
if k_n == 0:
  print(m)
  exit()
merge(knowers)
cnt = 0
parties = []
for _ in range(m):
  p_n, *party = map(int, input().split())
  merge(party)
  parties.append(party)

for party in parties:
  if find(party[0]) != find(knowers[0]):
    cnt += 1
print(cnt)
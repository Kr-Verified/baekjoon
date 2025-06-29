import sys
input = sys.stdin.readline
sys.setrecursionlimit(10001)

n = int(input())
graph = {i:[] for i in range(1, n+1)}
for _ in range(n-1):
  a, b, w = map(int, input().split())
  graph[a].append((b,w))
  graph[b].append((a,w))

def dfs(node, length):
  global maxv, maxNode
  if maxv < length:
    maxv = length
    maxNode = node

  for vertex, weight in graph[node]:
    if weight!=0 and not visited[vertex]:
      visited[vertex] = True
      dfs(vertex, length+weight)

maxv = 0
maxNode = 1
visited = [False]*(n+1)
visited[1] = True
dfs(1, 0)

visited = [False]*(n+1)
visited[maxNode] = True
dfs(maxNode, 0)

print(maxv)
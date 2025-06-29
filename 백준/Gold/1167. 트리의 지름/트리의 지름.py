import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)

n = int(input())
graph = {}
for _ in range(n):
  line = list(map(int, input().split()))
  value = [(line[i], line[i+1]) for i in range(1, len(line)-1, 2)]
  graph[line[0]] = value

def dfs(node, length):
  global maxv, maxNode
  if length>maxv:
    maxv = length
    maxNode = node
  for vertex, weight in graph[node]:
    if not visited[vertex]:
      visited[vertex] = True
      dfs(vertex, length+weight)

visited = [False]*(n+1)
visited[1] = True
maxv = 0
maxNode = 0
dfs(1, 0)

visited = [False]*(n+1)
visited[maxNode] = True
dfs(maxNode, 0)

print(maxv)
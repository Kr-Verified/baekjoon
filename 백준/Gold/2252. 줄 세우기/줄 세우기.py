from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
graph = {i : [] for i in range(1, n+1)}
in_degree = [0]*(n+1)

for _ in range(m):
  f, t = map(int, input().split())
  graph[f].append(t)
  in_degree[t]+=1

sequence = []
queue = deque()
for i in range(1, n+1):
  if in_degree[i]==0:
    queue.append(i)
while queue:
  x = queue.popleft()
  sequence.append(x)
  for next in graph[x]:
    in_degree[next]-=1
    if in_degree[next]==0:
      queue.append(next)
        
print(*sequence)
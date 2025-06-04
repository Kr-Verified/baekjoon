from collections import deque
import sys
input = sys.stdin.readline

for _ in range(int(input())):
  n, k = map(int, input().split())
  d = list(map(int, input().split()))
  apt = {i:[] for i in range(1, n+1)}
  in_degree = [0]*(n+1)
  for _ in range(k):
    f, t = map(int, input().split())
    apt[f].append(t)
    in_degree[t]+=1
  w = int(input())

  time = [0]*(n+1)
  queue = deque()
  for i in range(1, n+1):
    if in_degree[i]==0:
      queue.append(i)
      time[i] = d[i-1]
  while queue:
    x = queue.popleft()
    for next in apt[x]:
      time[next] = max(time[next], time[x]+d[next-1])
      in_degree[next]-=1
      if in_degree[next]==0:
        queue.append(next)
        
  print(time[w])
from collections import deque
import sys
input = sys.stdin.readline

ln, sn = map(int, input().split())
move = {}
for _ in range(ln+sn):
  f, t = map(int, input().split())
  move[f] = t

broad = [0]*101
queue = deque([1])
while queue:
  current = queue.popleft()
  for i in range(1, 7):
    next = current+i
    if next>100:
      break
    if next in move:
      next = move[next]
    if broad[next]==0:
      broad[next] = broad[current]+1
      queue.append(next)

print(broad[100])
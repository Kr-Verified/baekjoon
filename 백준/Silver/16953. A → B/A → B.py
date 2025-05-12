from collections import deque

a, b = map(int, input().split())

queue = deque()
queue.append((a, 1))
found = False

while queue:
  node, t = queue.popleft()
  if node == b:
    print(t)
    found = True
    break

  if node*2<=b:
    queue.append((node*2, t+1))
  if node*10+1<=b:
    queue.append((node*10+1, t+1))

if not found:
  print(-1)
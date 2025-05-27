from collections import deque
import sys
input = sys.stdin.readline

answer = []
for _ in range(int(input())):
  f, t = map(int, input().split())
  command = ['']*10000
  visited = [-1]*10000
  queue = deque()
  queue.append(f)
  visited[f] = f
  while queue:
    x = queue.popleft()
    if x==t:
      break
    for a, op in [(x*2%10000, 'D'), (9999 if x==0 else x-1, 'S'), ((x%1000)*10+x//1000, 'L'), ((x%10)*1000+x//10, 'R')]:
      if visited[a] == -1:
        queue.append(a)
        visited[a] = x
        command[a] = op
  result = []
  current = t
  while current!=f:
    result.append(command[current])
    current = visited[current]
  answer.append(''.join(reversed(result)))
sys.stdout.write('\n'.join(answer)+'\n')
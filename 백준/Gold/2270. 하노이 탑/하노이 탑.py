import sys
from collections import deque
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def hanoi(n, col):
  global result
  if n==0: return
  for i in range(3):
    if lis[i] and lis[i][0]==n:
      if i==col:
        lis[i].popleft()
        hanoi(n-1, col)
      else:
        temp = 3-i-col
        lis[i].popleft()
        hanoi(n-1, temp)
        result=(result+powers[n-1])%1000000
        return

result = 0
lis = []
n = int(input())
a, b, c = map(int, input().split())
powers = [1]
for i in range(1, n+1):
  powers.append((powers[i-1]*2)%1000000)
for i in range(3):
    lis.append(deque(map(int, input().split())))
for i in range(3):
  if lis[i] and lis[i][0]==n:
    lis[i].popleft()
    hanoi(n-1, i)
    print(i+1)
    print(result)
    break
def millar_rabin(n):
  if n in (2, 3):
    return True
  if n < 2 or n % 2 == 0:
    return False
  
  s = 0
  d = n -1
  while (d % 2 == 0):
    d //= 2
    s += 1

  for a in [2, 3, 5, 7, 11, 13, 17]:
    if a >= n:
      break
    x = pow(a, d, n)
    if x == 1 or x == n - 1:
      continue
    for _ in range(s - 1):
      x = pow(x, 2, n)
      if x == n - 1:
        break
    else:
      return False
  return True

import sys
input = sys.stdin.readline

n = int(input())
count = 0
for _ in range(n):
  x = int(input())
  check = millar_rabin(2*x+1)
  if check:
    count += 1

print(count)
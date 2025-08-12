import sys
sys.setrecursionlimit(10**7)

def gcd(a, b):
  while b != 0:
    a, b = b, a % b
  return a

def miller_rabin(n):
  if n in (2, 3):
    return True
  if n < 2 or n % 2 == 0:
    return False
  
  s = 0
  d = n - 1
  while d % 2 == 0:
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

def pollard_rho(n, x=2):
  g = lambda x: (x * x + 1) % n
  temp, y, d = x, x, 1
  
  for i in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71]:
    if n % i == 0:
      return i

  while True:
    while d == 1:
      x = g(x)
      y = g(g(y))
      d = gcd(abs(x - y), n)
    if d == n:
      temp += 1
      x = temp
      y = temp
      d = 1
    else:
      if miller_rabin(d):
        return d
      else:
        return pollard_rho(d, 2)
    
n = int(input())
answer = []
while n != 1:
  if miller_rabin(n):
    answer.append(n)
    break
  prime = pollard_rho(n, 2)
  answer.append(prime)
  n //= prime
for value in sorted(answer):
  print(value)
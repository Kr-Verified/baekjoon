def gcd(a, b):
  while b != 0:
    a, b = b, a % b
  return a

def is_prime(n):
  if n <= 71:
    return n in (2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71)
  if n % 2 == 0:
    return False
  return miller_rabin(n)

def miller_rabin(n):
  d = n -1
  s = 0
  while d % 2 == 0:
    d //= 2
    s += 1
  
  for a in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]:
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

def pollard_rho(n, x = 2):
  if is_prime(n):
    return n
  for i in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]:
    if n % i == 0:
      return i
    
  g = lambda x: (x * x + 1) % n
  temp, y, d = x, x, 1
  while True:
    while d == 1:
      x = g(x)
      y = g(g(y))
      d = gcd(abs(x - y), n)
    if d == n:
      temp += 1
      x, y, d = temp, temp, 1
    else:
      if is_prime(d):
        return d
      else:
        return pollard_rho(d)

while True:
  n = int(input())
  if n == 0:
    break
  if n == 1:
    print(0)
    continue
  answer = set()
  k = n
  while k != 1:
    p = pollard_rho(k)
    k //= p
    answer.add(p)
  
  for p in answer:
    n = n // p * (p - 1)
  print(n)
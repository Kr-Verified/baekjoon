def buy1(n):
  global result
  result += B * fac[n]

def buy2(n):
  global result
  m = min(fac[n], fac[n+1])
  fac[n] -= m
  fac[n+1] -= m
  result += (B + C) * m

def buy3(n):
  global result
  m = min(fac[n], fac[n+1], fac[n+2])
  fac[n] -= m
  fac[n+1] -= m
  fac[n+2] -= m
  result += (B + 2 * C) * m

n, B, C = map(int, input().split())
fac = list(map(int, input().split())) + [0, 0]
result = 0

if B > C:
  for i in range(n):
    if fac[i+2] < fac[i+1]:
      m = min(fac[i], fac[i+1]-fac[i+2])
      fac[i] -= m
      fac[i+1] -= m
      result += (B + C) * m
      buy3(i)
      buy1(i)
    else:
      buy3(i)
      buy2(i)
      buy1(i)
else:
  for i in range(n):
    buy1(i)
    
print(result)
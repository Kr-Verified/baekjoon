a, n, m = map(int, input().split())
a%=m
result = 1
def mod(a, n):
  if n==1:
    return a
  elif n%2==0:
    half = mod(a, n//2) % m
    return (half*half)%m
  half = mod(a, (n-1)//2) % m
  return (a*half*half)%m

print(mod(a, n))
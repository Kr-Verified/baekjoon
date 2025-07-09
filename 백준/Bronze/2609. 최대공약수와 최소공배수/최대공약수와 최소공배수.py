a, b = map(int, input().split())

def gcd(a, b):
  if b==0:
    print(a)
    return a
  return gcd(b, a%b)

def lcm(a, b):
  temp = gcd(a, b)
  return a*b//temp

print(lcm(a, b))
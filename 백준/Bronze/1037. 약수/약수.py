n = int(input())
nums = list(map(int, input().split()))

def gcd(a, b):
  while b!=0:
    a, b = b, a%b
  return a

maxv, minv = max(nums), min(nums)
print(max(minv, gcd(maxv, minv))*maxv)
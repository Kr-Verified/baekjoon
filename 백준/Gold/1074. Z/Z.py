import math

def z(x, y, size, i):
  if size==1:
    print(i)
    return
  
  global r, c
  half = size//2
  if x+half<=r:
    if y+half<=c:
      z(x+half, y+half, half, i+3*half*half)
    else:
      z(x+half, y, half, i+2*half*half)
  else:
    if y+half<=c:
      z(x, y+half, half, i+half*half)
    else:
      z(x, y, half, i)

n, r, c = map(int, input().split())
z(0, 0, 2**n,0)
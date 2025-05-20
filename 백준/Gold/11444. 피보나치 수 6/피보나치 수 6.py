MOD = 1_000_000_007

def mul(a, b):
  return [
    [(a[0][0]*b[0][0]+a[0][1]*b[1][0])%MOD, (a[0][0]*b[0][1]+a[0][1]*b[1][1])%MOD],
    [(a[1][0]*b[0][0]+a[1][1]*b[1][0])%MOD, (a[1][0]*b[0][1]+a[1][1]*b[1][1])%MOD]
  ]

def pow(mat, n):
  if n==1:
    return mat
  half = pow(mat, n//2)
  result = mul(half, half)
  if n%2==1:
    result = mul(result, mat)
  return result

def fibo(n):
  if n==0:
    return 0
  mat = [[1, 1], [1, 0]]
  result = pow(mat, n)
  return result[1][0]

print(fibo(int(input())))
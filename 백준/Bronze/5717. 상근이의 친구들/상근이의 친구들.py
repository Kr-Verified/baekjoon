a, b = -1, -1

while True:
  a, b = map(int, input().split())
  if a==b==0: break
  print(a+b)
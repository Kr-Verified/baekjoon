n, l = map(int, input().split())
found = False

for i in range(l, 101):
  result = n-i*(i-1)//2
  if result<0:
    break
  elif result%i==0:
    print(' '.join([str(i) for i in range(result//i, result//i+i)]))
    found = True
    break

if not found:
  print(-1)
n, w, h = map(int, input().split())
t = w*w+h*h
for _ in range(n):
  v = int(input())
  if v*v > t:
    print("NO")
  else:
    print("YES")
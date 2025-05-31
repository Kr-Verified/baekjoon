n = int(input())
pre, cur = 1, 1
for i in range(n-1):
  pre, cur = cur, (cur+pre*2)%10007
print(cur)
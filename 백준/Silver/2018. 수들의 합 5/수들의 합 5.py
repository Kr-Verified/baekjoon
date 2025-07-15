n = int(input())

cnt = 0
for k in range(1, n+1):
  temp = n - (k*(k-1))//2
  if temp%k == 0 and temp>0:
    cnt += 1
print(cnt)
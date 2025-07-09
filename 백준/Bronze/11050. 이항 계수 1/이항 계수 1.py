n, k = map(int, input().split())
sum = 1
if k>n-k:
  k = n-k
for i in range(n, n-k, -1):
  sum*=i
for i in range(2, k+1, 1):
  sum//=i
print(1 if k==0 else sum)
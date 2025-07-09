n = int(input())
result = 0

prime = [False]*2 + [True]*(n-1)
for i in range(2, int((n**0.5))+1):
  for j in range(i*i, n+1, i):
    prime[j]=False
  
dp = [0]
idx = 0
for i in range(n+1):
  if prime[i]:
    dp.append(dp[idx]+i)
    idx+=1

left, right, cnt = 1, 1, 0
while left<=right and right<=idx:
  if dp[right]-dp[left-1]>n:
    left+=1
  elif dp[right]-dp[left-1]<n:
    right+=1
  else:
    cnt+=1
    left+=1
print(cnt)
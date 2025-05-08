length = int(input())
arr = list(map(int, input().split()))
dp, t = [1]*length, [-1]*length

for i in range(length):
  for j in range(i):
    if arr[i]>arr[j] and dp[i]<dp[j]+1:
      dp[i], t[i] = dp[j]+1, j

maxLen = max(dp)
idx = dp.index(maxLen)
answer = []
while idx!=-1:
  answer.append(str(arr[idx]))
  idx = t[idx]
  
answer.reverse()

print(maxLen)
print(' '.join(answer))
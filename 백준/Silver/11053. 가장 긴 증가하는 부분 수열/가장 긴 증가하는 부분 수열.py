n = int(input())
nums = list(map(int, input().split()))
increase = [1 for _ in range(n)]

maxl = 1
for i in range(n):
  for j in range(i):
    if nums[i]>nums[j]:
      increase[i] = max(increase[i], increase[j]+1)
      maxl = max(maxl, increase[i])

print(maxl)
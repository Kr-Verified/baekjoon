n, m = map(int, input().split())
nums = list(map(int, input().split()))

nums.sort()
max_value = 0

for i in range(2, n):
  for j in range(1, i):
    for k in range(j):
      temp = nums[i]+nums[j]+nums[k]
      if temp <= m:
        max_value = max(max_value, temp)

print(max_value)
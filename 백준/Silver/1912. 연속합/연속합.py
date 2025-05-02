n = int(input())
nums = list(map(int, input().split()))
maxv = nums[0]
sumv = 0
for num in nums:
  sumv = max(num, sumv+num)
  if maxv<sumv:
    maxv=sumv
  
print(maxv)
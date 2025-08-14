def lower_bound(arr, n, target):
  left, right = 0, n
  while left < right:
    mid = (left + right) // 2
    if arr[mid] < target:
      left = mid + 1
    else:
      right = mid
  return left

n = int(input())
nums = list(map(int, input().split()))
dp = []

for i in range(n):
  lower = lower_bound(dp, len(dp), nums[i])
  if lower == len(dp):
    dp.append(nums[i])
  else:
    dp[lower] = nums[i]
print(len(dp))
nums = [list(map(int, input().split())) for _ in range(int(input()))]

for i in range(len(nums)):
  print(*nums[i])
  if 17 in nums[i]:
    if 18 in nums[i]:
      print("both")
    else:
      print("zack")
  elif 18 in nums[i]:
    print("mack")
  else:
    print("none")
  print()
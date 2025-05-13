nums = map(int, input().split())
sum = 0

for n in nums:
  sum += n*n

print(sum%10)
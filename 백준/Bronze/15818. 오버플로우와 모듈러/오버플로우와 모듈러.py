n, m = map(int, input().split())
nums = list(map(int, input().split()))

result = 1
for i in nums:
    result = (result * (i % m)) % m

print(result)
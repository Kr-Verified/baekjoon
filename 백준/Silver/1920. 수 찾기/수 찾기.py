n = int(input())
nums = set(map(int, input().split()))
m = int(input())
for i in list(map(int, input().split())):
    if i in nums:
        print(1)
    else:
        print(0)
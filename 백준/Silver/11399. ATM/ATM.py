n = int(input())
p = sorted(list(map(int, input().split())))
result, sum = 0, 0
for i in p:
  result+=i
  sum+=result
print(sum)
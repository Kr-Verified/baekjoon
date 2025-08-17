n = int(input())
size = list(map(int, input().split()))
t, p = map(int, input().split())

result = 0
for i in size:
  result += (i+t-1)//t

print(result)
print(n//p, n-(n//p)*p)
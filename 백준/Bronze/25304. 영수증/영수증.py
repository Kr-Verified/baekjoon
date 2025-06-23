money = int(input())
sum = 0
for _ in range(int(input())):
  m, n = map(int, input().split())
  sum+=m*n

print("Yes" if money==sum else "No")
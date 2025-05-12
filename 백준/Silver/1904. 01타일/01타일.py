n = int(input())
a, b = 2, 1

for i in range(1, n):
    a, b = (a+b)%15746, a

print(b)
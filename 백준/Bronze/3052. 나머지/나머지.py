modify = [0]*42
for _ in range(10):
  n = int(input())
  modify[n%42] = 1
print(sum(modify))
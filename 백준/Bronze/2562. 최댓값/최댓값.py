maxd = (0, 0)
for i in range(1, 10):
  n = int(input())
  if n>maxd[1]:
    maxd = (i, n)
print(maxd[1], '\n', maxd[0], sep='')
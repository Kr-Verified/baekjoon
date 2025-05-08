n, d, p = int(input()), list(map(int, input().split())), list(map(int, input().split()))
minp, total, move = p[0], p[0]*d[0], 0

for i in range(1, len(d)):
  if minp>p[i]:
    total += minp*move
    minp, move = p[i], 0
  move+=d[i]

if move:
  total+=minp*move
  
print(total)
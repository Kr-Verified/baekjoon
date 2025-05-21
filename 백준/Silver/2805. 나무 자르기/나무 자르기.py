n, m = map(int, input().split())
woods = list(map(int, input().split()))
result = 0
bottom, top = 0, max(woods)

while bottom<=top:
  mid = (bottom+top)//2
  total = sum([(wood-mid) for wood in woods if wood>mid])

  if total>=m:
    result = mid
    bottom = mid+1
  else:
    top = mid-1

print(result)
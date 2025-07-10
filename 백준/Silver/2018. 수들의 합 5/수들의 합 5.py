n = int(input())
cnt = 0
total, left, right = 1, 1, 1

while left<=n:
  if total<n:
    right+=1
    total+=right
  elif total>n:
    total-=left
    left+=1
  else:
    total-=left
    left+=1
    cnt+=1

print(cnt)
    
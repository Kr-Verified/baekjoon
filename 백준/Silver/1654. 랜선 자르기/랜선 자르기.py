k, n = map(int, input().split())
rens = [int(input()) for _ in range(k)]
std = 0

left, right = 1, max(rens)
while left<=right:
  mid = (left+right)//2
  result = sum(ren//mid for ren in rens)
  if result>=n:
    left = mid+1
    if std<mid:
      std=mid
  elif result<n:
    right = mid-1
print(std)
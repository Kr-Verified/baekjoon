import sys
input = sys.stdin.readline

def merge(arr, left, mid, right):
  g1 = arr[left:mid+1]
  g2 = arr[mid+1:right+1]

  g, gg, a = 0, 0, left
  while g < len(g1) and gg < len(g2):
    if g1[g] < g2[gg]:
      arr[a] = g1[g]
      g += 1
    else:
      arr[a] = g2[gg]
      gg += 1
    a += 1
  
  while g < len(g1):
    arr[a] = g1[g]
    g += 1
    a += 1
  while gg < len(g2):
    arr[a] = g2[gg]
    gg += 1
    a += 1

def merge_sort(arr, left, right):
  if left >= right:
    return
  mid = left + (right - left) // 2
  merge_sort(arr, left, mid)
  merge_sort(arr, mid+1, right)
  merge(arr, left, mid, right)

nums = [int(input()) for _ in range(int(input()))]
merge_sort(nums, 0, len(nums)-1)
for num in nums:
  print(num)
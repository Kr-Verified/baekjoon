n, m = map(int, input().split())
nums = sorted(map(int, input().split()))

result = []
selected = set()
def back(idx, len):
  if len==m:
    temp = " ".join(result)
    if temp not in selected:
      print(temp)
      selected.add(temp)
    return
  for i in range(idx, n):
    result.append(str(nums[i]))
    back(i, len+1)
    result.pop()

back(0, 0)
n, m = map(int, input().split())
nums = sorted(list(map(int, input().split())))
result = []

def dfs(length):
  if length==m:
    print(*result)
    return
  for vertex in range(0, n):
    if nums[vertex] not in result:
      result.append(nums[vertex])
      dfs(length+1)
      result.pop()

dfs(0)
n, m = map(int, input().split())
nums = sorted(list(map(int, input().split())))
result = []
visited = [False]*n
history = set()

def dfs(length):
  if length==m:
    temp = tuple(result)
    if temp not in history:
      history.add(temp)
      print(*temp)
    return
  
  for idx in range(0, n):
    if not visited[idx]:
      visited[idx]=True
      result.append(nums[idx])
      dfs(length+1)
      result.pop()
      visited[idx]=False

dfs(0)
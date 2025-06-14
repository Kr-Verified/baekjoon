n, m = map(int, input().split())
result = []

def dfs(node, length):
  if length==m:
    print(' '.join(map(str, result)))
    return
  
  for vertex in range(node+1, n+1):
    result.append(vertex)
    dfs(vertex, length+1)
    result.pop()

dfs(0, 0)
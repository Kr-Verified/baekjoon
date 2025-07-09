n, l = map(int, input().split())
result = []

def back(length):
  if length == l:
    print(" ".join(result))
    return
  for i in range(1, n+1):
    result.append(str(i))
    back(length+1)
    result.pop()

back(0)
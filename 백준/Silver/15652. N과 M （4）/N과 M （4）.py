n, length = map(int, input().split())
result = []
def back(s, c):
  if c==length:
    print(' '.join(result))
    return
  for i in range(s, n+1):
      result.append(str(i))
      back(i, c+1)
      result.pop()

back(1, 0)
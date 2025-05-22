n = int(input())
xs = list(map(int, input().split()))
smallX = sorted(list(set(xs)))
dicX = {v: i for i, v in enumerate(smallX)}
for num in xs:
  print(dicX[num], end=' ')
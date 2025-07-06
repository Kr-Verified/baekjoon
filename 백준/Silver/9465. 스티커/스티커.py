for _ in range(int(input())):
  n = int(input())
  sticker = []
  sticker.append(list(map(int, input().split())))
  sticker.append(list(map(int, input().split())))
  scores = [[0 for _ in range(n+1)] for _ in range(2)]
  scores[0][1], scores[1][1] = sticker[0][0], sticker[1][0]
  for i in range(2, n+1):
    scores[0][i] = max(scores[1][i-1], scores[1][i-2]) + sticker[0][i-1]
    scores[1][i] = max(scores[0][i-1], scores[0][i-2]) + sticker[1][i-1]
  print(max(scores[0][n], scores[1][n]))
cogwheel = [list(map(int, list(input()))) for _ in range(4)]
next = [0 for _ in range(4)]

def wheel_turn(n, direction):
  if n<0 or n>3:
    return
  visited[n] = True
  cleft, cright = (next[n]+6)%8, (next[n]+2)%8
  if n > 0:
    pright = (next[n-1]+2)%8
    if not visited[n-1] and cogwheel[n][cleft] != cogwheel[n-1][pright]:
      wheel_turn(n-1, -direction)
  if n < 3:
    nleft = (next[n+1]+6)%8
    if not visited[n+1] and cogwheel[n][cright] != cogwheel[n+1][nleft]:
      wheel_turn(n+1, -direction)

  next[n] = (next[n]+direction)%8
  if next[n] < 0:
    next[n] += 8

for _ in range(int(input())):
  n, direction = map(int, input().split())
  visited = [False] * 4
  wheel_turn(n-1, -direction)

score = 0
for i in range(4):
  score += cogwheel[i][next[i]] * (2**i)

print(score)
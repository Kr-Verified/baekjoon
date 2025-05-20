import sys
input = sys.stdin.readline

n = int(input())
papers = []
white = 0
blue = 0

def f(x, y, size):
  global white, blue
  first = papers[x][y]
  for i in range(x, x+size):
      for j in range(y, y+size):
         if first!=papers[i][j]:
            h = size//2
            f(x, y, h)
            f(x+h, y, h)
            f(x, y+h, h)
            f(x+h, y+h, h)
            return
  if first==1:
     blue+=1
  else:
     white+=1

# 입력
for _ in range(n):
  papers.append(list(map(int, input().split())))

f(0, 0, n)
print(f'{white}\n{blue}')
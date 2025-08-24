days = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
y, m, d = 2014, 4, 1

n = int(input())
while n > 0:
  temp = days[m]-d+1
  if m == 2 and ((y % 4 == 0 and y % 100 != 0) or y % 400 == 0):
    temp += 1
  if n >= temp:
    n -= temp
    d = 1
    m += 1
    if m == 13:
      m = 1
      y += 1
  else:
    d += n
    n = 0

print(f"{y:02d}-{m:02d}-{d:02d}")
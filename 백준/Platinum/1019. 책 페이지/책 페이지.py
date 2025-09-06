number = int(input())
cnt = [0] * 10

d = 1
while len(str(d)) <= len(str(number)):
  high = number // (d*10)
  cur = (number // d) % 10
  low = number % d
  if cur > 0:
    cnt[0] += high * d
  else:
    cnt[0] += (high - 1) * d + low + 1
  for i in range(1, 10):
    if cur > i:
      cnt[i] += (high + 1) * d
    elif cur == i:
      cnt[i] += high * d + low + 1
    elif cur < i:
      cnt[i] += (high - 1) * d + d
  d *= 10

print(*cnt)
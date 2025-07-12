n = int(input())
room_price = list(map(int, input().split()))
m = int(input())

number = ['']*(m+1)

def is_better(a, b):
  if len(a)!=len(b):
    return len(a)>len(b)
  return a>b

for i in range(m+1):
  for rp in range(n):
    price = room_price[rp]
    if i>=price:
      temp = number[i-price]+str(rp)
      if temp=='0': continue
      if is_better(temp, number[i]):
        number[i] = temp

print(0 if number[m]=='' else number[m])
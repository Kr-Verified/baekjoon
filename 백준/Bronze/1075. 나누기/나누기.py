n, a = int(input())//100*100, int(input())

for i in range(0, 100):
  if (n+i)%a==0:
    print(f"{i:02d}")
    break
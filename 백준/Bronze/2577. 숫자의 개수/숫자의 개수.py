a = int(input())
b = int(input())
c = int(input())
cnt = [0]*10

for i in str(a*b*c):
  cnt[int(i)]+=1

for i in cnt:
  print(i)
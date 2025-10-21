n = int(input())
m = int(input())
s = input()

string = "I" + "OI"*n;
cnt = 0

for i in range(m - (2*n)):
  if string == s[i:i + 2*n + 1]:
    cnt += 1

print(cnt)
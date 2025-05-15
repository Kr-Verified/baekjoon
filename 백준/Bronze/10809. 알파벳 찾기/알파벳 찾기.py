a = [-1]*26
str = input()
for i in range(len(str)):
  if a[ord(str[i])-97]==-1:
    a[ord(str[i])-97]=i
print(*a)
alpha = [0]*26
a = input()
b = input()
for i in a:
  alpha[ord(i)-97]+=1
for i in b:
  alpha[ord(i)-97]-=1

for i in range(26):
  alpha[i] = max(alpha[i], -alpha[i])
print(sum(alpha))
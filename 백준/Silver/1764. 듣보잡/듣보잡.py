import sys
sysInput = sys.stdin.readline

l, s = map(int, sysInput().split())
listen = [sysInput() for _ in range(l)]
see = set(sysInput() for _ in range(s))

dic = []
for name in listen:
  if name in see:
    dic.append(name)

print(len(dic))
for result in sorted(dic):
  print(result, end='')
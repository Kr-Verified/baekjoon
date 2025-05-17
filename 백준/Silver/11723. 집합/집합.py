import sys
sysInput = sys.stdin.readline
s = set()

for _ in range(int(sysInput())):
  command, *rest = sysInput().split()
  if rest:
    x = int(rest[0])
  if command=="add":
    s.add(x)
  elif command=="remove":
    s.discard(x)
  elif command=="check":
    print(str(int(x in s)))
  elif command=="toggle":
    if x in s:
      s.remove(x)
    else:
      s.add(x)
  elif command=="all":
    s = set(range(1, 21))
  elif command=="empty":
    s.clear()
def last(a, b):
  cycle = []
  current = a%10
  while current not in cycle:
    cycle.append(current)
    current = (current*a)%10
  return cycle[(b-1)%len(cycle)]

for _ in range(int(input())):
  a, b = map(int, input().split())
  result = last(a, b)
  print(10 if result==0 else result%10)
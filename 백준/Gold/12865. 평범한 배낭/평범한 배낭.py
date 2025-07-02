n, k = map(int, input().split())
things = []
for _ in range(n):
  w, v = map(int, input().split())
  things.append((w, v))

values = [0]*100001
for w, v in things:
 for weight in range(k, w-1, -1):
   values[weight] = max(values[weight], values[weight-w]+v)

print(values[k])
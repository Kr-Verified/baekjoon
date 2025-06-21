n, m = map(int, input().split())
cities = {i:[] for i in range(1, n+1)}
min_time = [float('inf')]*(n+1)
for _ in range(m):
  a, b, c = map(int, input().split())
  cities[a].append((b, c))
def ball():
  min_time[1] = 0
  for i in range(n):
    for route in range(1, n+1):
      for vertex, time in cities[route]:
        if min_time[route]!=float('inf') and min_time[route]+time<min_time[vertex]:
          if i==n-1:
            return True
          min_time[vertex]=min_time[route]+time
  return False
if ball():
  print(-1)
else:
  for i in min_time[2:]:
    print(-1 if i==float('inf') else i)
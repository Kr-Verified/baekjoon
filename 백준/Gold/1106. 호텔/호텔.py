goal, n = map(int, input().split())
cost = []
value = []

for _ in range(n):
  a, b = map(int, input().split())
  cost.append(a)
  value.append(b)

maximum = goal+max(value)+1
city = [float('inf')]*(maximum)
city[0] = 0

for i in range(n):
  for j in range(value[i], maximum):
    city[j] = min(city[j], city[j-value[i]]+cost[i])

print(min(city[goal:]))
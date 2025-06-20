tc = int(input())
for _ in range(tc): #테스트 케이스 반복
  n, m, w = map(int, input().split())
  graph = {i:[] for i in range(1, n+1)}
  min_time = [1000000]*(n+1)
  # 도로 입력
  for _ in range(m):
    s, e, t = map(int, input().split())
    graph[s].append((e, t))
    graph[e].append((s, t))
  # 웜홀 입력
  for _ in range(w):
    s, e, t = map(int, input().split())
    graph[s].append((e, -t))
  # 벨만-포드
  def bal():
    for i in range(n):
      for route in range(1, n+1):
        for v, t in graph[route]:
          if min_time[route]+t < min_time[v]:
            if i==n-1:
              return True
            min_time[v] = min_time[route]+t
    return False

  print('YES' if bal() else 'NO')
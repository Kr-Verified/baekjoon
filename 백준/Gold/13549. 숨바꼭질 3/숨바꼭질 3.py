import heapq
n, k = map(int, input().split())
min_time = [float('inf')]*max(2*k+1, n)
queue = [(0, n)]

while queue:
  time, node = heapq.heappop(queue)
  if node==k:
    print(time)
    break
  
  if 0<node<k and min_time[node*2]>time:
    min_time[node*2]=time
    heapq.heappush(queue, (time, node*2))
  if node<k and min_time[node+1]>time:
    min_time[node+1]=time
    heapq.heappush(queue, (time+1, node+1))
  if node>0 and min_time[node-1]>time:
    min_time[node-1]=time
    heapq.heappush(queue, (time+1, node-1))
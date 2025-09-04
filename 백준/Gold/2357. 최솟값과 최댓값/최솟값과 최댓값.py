import sys
input = sys.stdin.readline

def build(node, start, end):
  if start == end:
    max_tree[node] = arr[start]
    min_tree[node] = arr[start]
  else:
    mid = (start + end) // 2
    build(node * 2, start, mid)
    build(node * 2 + 1, mid + 1, end)
    max_tree[node] = max(max_tree[node * 2], max_tree[node * 2 + 1])
    min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1])

def query_max(node, start, end, left, right):
  if right < start or end < left:
    return -1
  if left <= start and end <= right:
    return max_tree[node]
  mid = (start + end) // 2
  return max(query_max(node * 2, start, mid, left, right), query_max(node * 2 + 1, mid + 1, end, left, right))

def query_min(node, start, end, left, right):
  if right < start or end < left:
    return 1000000001
  if left <= start and end <= right:
    return min_tree[node]
  mid = (start + end) // 2
  return min(query_min(node * 2, start, mid, left, right), query_min(node * 2 + 1, mid + 1, end, left, right))

n, m = map(int, input().split())
arr = [int(input()) for _ in range(n)]
max_tree = [-1] * (n * 4)
min_tree = [1000000001] * (n * 4)
build(1, 0, n - 1)

for _ in range(m):
  a, b = map(int, input().split())
  max_val = query_max(1, 0, n - 1, a - 1, b - 1)
  min_val = query_min(1, 0, n - 1, a - 1, b - 1)
  print(min_val, max_val)
import sys
input = sys.stdin.readline

def build(node, start, end):
  if start == end:
    tree[node] = arr[start]
  else:
    mid = (start + end) // 2
    build(node * 2, start, mid)
    build(node * 2 + 1, mid + 1, end)
    tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % 1000000007

def query(node, start, end, left, right):
  if right < start or end < left:
    return 1
  if left <= start and end <= right:
    return tree[node]
  mid = (start + end) // 2
  return (query(node * 2, start, mid, left, right) * query(node * 2 + 1, mid + 1, end, left, right)) % 1000000007

def update(node, start, end, idx, val):
  if start == end:
    tree[node] = val
  else:
    mid = (start + end) // 2
    if idx <= mid:
      update(node * 2, start, mid, idx, val)
    else:
      update(node * 2 + 1, mid + 1, end, idx, val)
    tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % 1000000007

n, m, k = map(int, input().split())
arr = [int(input()) for _ in range(n)]
tree = [1] * (n * 4)
build(1, 0, n - 1)
for _ in range(m + k):
  a, b, c = map(int, input().split())
  if a == 1:
    update(1, 0, n - 1, b - 1, c)
  elif a == 2:
    print(query(1, 0, n - 1, b - 1, c - 1))
import sys
input = sys.stdin.readline

def build(node, start, end):
    if start == end:
        tree[node] = arr[start]
    else:
        mid = (start + end) // 2
        build(node * 2, start, mid)
        build(node * 2 + 1, mid + 1, end)
        tree[node] = min(tree[node * 2], tree[node * 2 + 1])

def quary(node, start, end, left, right):
    if right < start or left > end:
        return 1000000001
    if left <= start and right >= end:
        return tree[node]
    mid = (start + end) // 2
    return min(quary(node * 2, start, mid, left, right), quary(node * 2 + 1, mid + 1, end, left, right))

n, m = map(int, input().split())
arr = [int(input()) for _ in range(n)]
tree = [1000000001] * (n * 4)
build(1, 0, n-1)

for _ in range(m):
    a, b = map(int, input().split())
    print(quary(1, 0, n-1, a-1, b-1))
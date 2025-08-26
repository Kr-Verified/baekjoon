n, k = map(int, input().split())
arr = [i for i in range(1, n+1)]

idx = 0
result = []
while arr:
  idx = (idx + k - 1) % len(arr)
  result.append(str(arr[idx]))
  del arr[idx]

print(f'<{", ".join(result)}>')
n, m = map(int, input().split())

prime = [False, False] + [True]*(m-1)

for i in range(2, int(m**0.5)+1):
  for j in range(i*i, m+1, i):
    prime[j] = False

for i in range(n, m+1):
  if prime[i]:
    print(i)
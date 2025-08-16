for _ in range(int(input())):
  n = int(input())
  coins = list(map(int, input().split()))
  m = int(input())
  cases = [0 for _ in range(m+1)]
  cases[0] = 1

  for coin in coins:
    for i in range(coin, m+1):
      cases[i] += cases[i-coin]

  print(cases[m])
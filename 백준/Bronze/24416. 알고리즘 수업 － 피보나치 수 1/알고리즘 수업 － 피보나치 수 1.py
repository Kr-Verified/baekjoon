def fibonacci(n):
  f[1] = f[2] = 1;
  for i in range(3, n+1):
    f[i] = f[i - 1] + f[i - 2];
  print(f[n], max(1, n-2))

n = int(input())
f = [0]*max(4, n+1)
fibonacci(n)
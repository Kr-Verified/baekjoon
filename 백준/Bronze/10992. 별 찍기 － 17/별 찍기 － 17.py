n = int(input())
print(' '*(n-1), '*', sep='')
for i in range(1, n-1):
    print(' '*(n-i-1), '*', ' '*(2*i-1), '*', sep='')
if n!=1:
  print('*'*(2*n-1))
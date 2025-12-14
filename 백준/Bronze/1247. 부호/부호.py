for i in range(3):
  n = int(input())
  result = 0
  for i in range(n):
    a = int(input())
    result += a
  if (result > 0): print("+")
  elif (result < 0): print("-")
  else: print("0")
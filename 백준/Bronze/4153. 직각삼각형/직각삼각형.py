while (1):
  a, b, c = map(int, input().split())
  if (a==b==c==0): break
  A, B, C = a*a, b*b, c*c
  if ((A==B+C) or (B==A+C) or (C==A+B)):
    print("right")
  else:
    print("wrong")
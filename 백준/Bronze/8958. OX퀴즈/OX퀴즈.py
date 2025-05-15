for _ in range(int(input())):
  seq, score = 0, 0
  for s in input():
    if s=='O':
      seq+=1
      score+=seq
    else:
      seq=0
  print(score)
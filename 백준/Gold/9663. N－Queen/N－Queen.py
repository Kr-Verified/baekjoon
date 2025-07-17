n = int(input())

result = 0

def back(row, cols, d1, d2):
  global result
  if row==n:
    result+=1
    return
  
  able = ((1 << n)-1) & ~(cols|d1|d2)
  while able:
    pos = able & -able
    able -= pos
    back(row+1, cols|pos, (d1|pos)<<1, (d2|pos)>>1)

back(0, 0, 0, 0)
print(result)
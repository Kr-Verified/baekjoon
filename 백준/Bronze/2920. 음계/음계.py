n = list(map(int, input().split()))
increase, decrease= True, True

for i in range(len(n)-1):
  if n[i]!=n[i+1]-1:
    increase=False
  if n[i]!=n[i+1]+1:
    decrease=False

if increase:
  print("ascending")
elif decrease:
  print("descending")
else:
  print("mixed")
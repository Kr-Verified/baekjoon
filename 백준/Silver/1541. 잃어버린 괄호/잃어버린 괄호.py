datas = input().split('-')
total = sum(map(int, datas[0].split('+')))
for data in datas[1:]:
  total-=sum(map(int, data.split('+')))

print(total)
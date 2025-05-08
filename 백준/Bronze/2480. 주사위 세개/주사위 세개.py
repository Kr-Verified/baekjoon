dice = sorted(list(map(int, input().split())))
print(10000+dice[0]*1000 if dice[0]==dice[2] else (1000+dice[1]*100 if dice[0]==dice[1] or dice[1]==dice[2] else max(dice)*100))
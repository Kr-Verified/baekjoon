h, m = map(int, input().split())
time = h*60+m-45
time = time if time>=0 else time+1440
print(time//60, time%60)
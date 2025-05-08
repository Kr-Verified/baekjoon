h, m = map(int, input().split())
delay = int(input())
time = h*60+m+delay
time = time if time<1440 else time-1440
print(time//60, time%60)
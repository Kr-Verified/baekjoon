n = int(input())
arr = list(map(int, input().split()))
streak = 0
max_streak = 0

for i in arr:
    if i != 0:
        streak += 1
        if max_streak < streak:
            max_streak = streak
    else:
        streak = 0

print(max_streak)
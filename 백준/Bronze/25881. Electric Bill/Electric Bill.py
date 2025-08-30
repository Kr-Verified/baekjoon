import sys
input = sys.stdin.readline

base, extra = map(int, input().split())
n = int(input())
for _ in range(n):
    elec = int(input())
    if elec <= 1000:
        print(elec, elec*base)
    else:
        print(elec, 1000*base+(elec-1000)*extra)
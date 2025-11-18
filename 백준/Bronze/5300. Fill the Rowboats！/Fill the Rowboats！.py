import sys
input = sys.stdin.readline

n = int(input())

for i in range(1, n+1):
    sys.stdout.write(f"{i} ")
    if (i % 6 == 0): sys.stdout.write("Go! ")


if (n % 6 != 0): sys.stdout.write("Go! ");
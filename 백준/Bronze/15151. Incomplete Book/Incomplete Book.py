a, b = map(int, input().split())

i = 0
while True:
    b -= a
    a *= 2
    i += 1
    if (b < a): break

print(i)
def get(n):
    if '0' <= n <= '9':
        return ord(n) - ord('0')
    return ord(n) - ord('A') + 10

def conversion(n):
    if n < 10:
        return chr(n+ord('0'))
    return chr(n+55)

n = int(input())
numbers = [input().strip() for _ in range(n)]
k = int(input())

gain = [0] * 36

total_sum = 0

for v in numbers:
    length = len(v)
    for i, c in enumerate(v):
        integer = get(c)
        power = 36 ** (length - i - 1)
        total_sum += integer * power
        gain[integer] += (35 - integer) * power

gain.sort(reverse = True)

for i in range(k):
    total_sum += gain[i]

if total_sum == 0:
    print("0")
else:
    result = []
    while total_sum > 0:
        result.append(conversion(total_sum%36))
        total_sum //= 36
    
    print("".join(result[::-1]))
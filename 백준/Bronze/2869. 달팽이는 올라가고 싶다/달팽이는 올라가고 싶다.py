import math

n, k, v = map(int, input().split())
print(math.ceil((v-k)/(n-k)))
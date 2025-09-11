t = int(input())
n = int(input())
candies = list(map(int, input().split()))

print("Padaeng_i Happy" if sum(candies) >= t else "Padaeng_i Cry")
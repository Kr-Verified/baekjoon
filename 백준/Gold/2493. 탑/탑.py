import sys
input = sys.stdin.readline

n = int(input())
nums = list(map(int, input().split()))
tower = []
output = []

for i in range(n):
    while tower and nums[tower[-1]] < nums[i]:
        tower.pop()
    if tower:
        output.append(str(tower[-1] + 1))
    else:
        output.append("0")
    tower.append(i)

print(" ".join(output))

import sys
sys.setrecursionlimit(1000000)
def hanoi(n, fromp, to, anx):
    if n==1:
        print(fromp, to)
        return
    hanoi(n-1, fromp, anx, to)
    print(fromp, to)
    hanoi(n-1, anx, to, fromp)
n = int(input())
print(2**n-1)
hanoi(n, 1, 3, 2)
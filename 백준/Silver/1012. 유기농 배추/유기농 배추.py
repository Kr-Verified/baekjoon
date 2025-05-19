import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline

def dfs(y, x):
    visited[y][x] = True
    for dy, dx in [(-1,0), (1,0), (0,-1), (0,1)]:
        ny, nx = y + dy, x + dx
        if 0 <= ny < n and 0 <= nx < m:
            if field[ny][nx] == 1 and not visited[ny][nx]:
                dfs(ny, nx)

t = int(input())
for _ in range(t):
    m, n, k = map(int, input().split())
    field = [[0 for _ in range(m)] for _ in range(n)]
    visited = [[False for _ in range(m)] for _ in range(n)]
    cnt = 0
    
    for _ in range(k):
        x, y = map(int, input().split())
        field[y][x] = 1

    for y in range(n):
        for x in range(m):
            if field[y][x] == 1 and not visited[y][x]:
                dfs(y, x)
                cnt += 1
    print(cnt)

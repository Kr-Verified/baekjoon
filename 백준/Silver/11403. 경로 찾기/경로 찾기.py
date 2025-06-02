import sys
input = sys.stdin.readline

n = int(input())
ad_matrix = [list(map(int, input().split())) for _ in range(n)]
result_matrix = [[0 for _ in range(n)] for _ in range(n)]

def dfs(start, node):
    for i in range(n):
        if ad_matrix[node][i]==1 and not visited[i]:
            result_matrix[start][i] = 1
            visited[i] = True
            dfs(start, i)

for r in range(n):
    visited = [False]*n
    dfs(r, r)

for row in result_matrix:
    print(*row)
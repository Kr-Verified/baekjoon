#include <stdio.h>

int main(void)
{
    int n, m, a, b, c;
    int cost[101][101];
    scanf("%d", &n);
    scanf("%d", &m);
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i==j) cost[i][i] = 0;
            else cost[i][j] = 100000000;
        }
    }
    
    for (int i=0; i<m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        cost[a-1][b-1] = cost[a-1][b-1]<c?cost[a-1][b-1]:c;
    }
    
    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                int middle = cost[i][k]+cost[k][j];
                cost[i][j] = cost[i][j]<middle?cost[i][j]:middle;
            }
        }
    }
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d ", cost[i][j]==100000000?0:cost[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
#include <stdio.h>

int main(void) {
    int v, e, d[401][401], a, b, c, minv=1000000000;
    scanf("%d %d", &v, &e);
    
    for(int i=0; i<v; i++) for(int j=0; j<v; j++) d[i][j]=1000000000;
    
    for(int i=0; i<e; i++) {
        scanf("%d %d %d", &a, &b, &c);
        d[a-1][b-1] = d[a-1][b-1]<c?d[a-1][b-1]:c;
    }
    
    for(int k=0; k<v; k++) for(int i=0; i<v; i++) for(int j=0; j<v; j++) {
        int temp = d[i][k]+d[k][j];
        d[i][j] = d[i][j]<temp?d[i][j]:temp;
    }
    
    for(int i=0;i<v;i++) for(int j=0; j<v; j++) {
        int temp = d[i][j]+d[j][i];
        minv = minv<temp?minv:temp;
    }
    
    printf("%d", minv==1000000000?-1:minv);
    
    return 0;
}
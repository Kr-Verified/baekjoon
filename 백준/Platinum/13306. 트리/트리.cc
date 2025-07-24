#include <stdio.h>
#include <stdlib.h>

typedef struct Query {
  int type;
  int a, b;
} Query;

int find(int* parents, int x) {
  if (parents[x] == x) return x;
  int top = find(parents, parents[x]);
  parents[x] = top;
  return top;
}

void merge(int* rank, int *parents, int x, int y) {
  int a = find(parents, x);
  int b = find(parents, y);

  if (rank[a] > rank[b]) {
    parents[b] = a;
    rank[a] += rank[b];
    rank[b] = 0;
  }else {
    parents[a] = b;
    rank[b] += rank[a];
    rank[a] = 0;
  }
}

int main() {
  int N, Q, cnt = 0;
  scanf("%d %d", &N, &Q);
  int *parents = (int*)malloc(sizeof(int) * (N+1));
  int *ranks = (int*)malloc(sizeof(int) * (N+1));
  int *pInfo = (int*)malloc(sizeof(int) * (N+1));
  int *answer = (int*)malloc(sizeof(int) * Q);
  Query *queries = (Query*)malloc(sizeof(Query) * (Q+N-1));
  for (int i = 2; i <= N; i++) {
    scanf("%d", &pInfo[i]);
    parents[i] = i;
    ranks[i] = 1;
  }
  parents[1] = 1;
  ranks[1] = 1;

  for (int i = 0; i < Q+N-1; i++) {
    int type, a, b;
    scanf("%d", &type);
    if (type == 0) {
      scanf("%d", &a);
      queries[i] = (Query){type, a, 0};
    }else {
      scanf("%d %d", &a, &b);
      queries[i] = (Query){type, a, b};
    }
  }

  for (int i = Q+N-2; i >= 0; i--) {
    Query temp = queries[i];
    if (temp.type == 0) {
      if (find(parents, temp.a) != find(parents, pInfo[temp.a])) {
        merge(ranks, parents, temp.a, pInfo[temp.a]);
      }
    }else {
      if (find(parents, temp.a) == find(parents, temp.b)) {
        answer[cnt++] = 1;
      }else {
        answer[cnt++] = 0;
      }
    }
  }

  for (int i = cnt-1; i >= 0; i--) {
    printf("%s\n", answer[i]==1?"YES":"NO");
  }

  free(parents);
  free(pInfo);
  free(ranks);
  free(answer);
  free(queries);
  return 0;
}
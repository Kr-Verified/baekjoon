#include <stdio.h>

int graph[1001][1001];
int graph_len[1001] = {0};
int indegree[1001] = {0};

int main(void) {
  int n, m, k, queue[100001], rear=0, front=0, result[1001];
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int prev, cur;
    scanf("%d %d", &k, &prev);
    for (int j = 1; j < k; j++) {
      scanf("%d", &cur);
      graph[prev][graph_len[prev]++] = cur;
      indegree[cur]++;
      prev = cur;
    }

  }

  for (int i = 1; i <= n; i++) {
    if (indegree[i] == 0) queue[rear++] = i;
  }

  int idx = 0;
  while (front < rear) {
    int vertex = queue[front++];
    result[idx++] = vertex;
    for (int i = 0; i < graph_len[vertex]; i++) {
      int next = graph[vertex][i];
      if (--indegree[next] == 0) {
        queue[rear++] = next;
      }
    }
  }

  if (idx < n) printf("0\n");
  else for (int i = 0; i < idx; i++) {
    printf("%d\n", result[i]);
  }
  return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int vertex;
  int left, right;
} Node;

int search(Node graph[], int key, int cnt) {
  if (cnt == 0) {
    graph[0] = (Node){key, -1, -1};
    return -1;
  }
  int idx = 0;
  while (1) {
    if (graph[idx].vertex < key) {
      if (graph[idx].right == -1) {
        graph[cnt] = (Node){key, -1, -1};
        graph[idx].right = cnt;
        return idx;
      }
      idx = graph[idx].right;
    }
    else if (graph[idx].vertex > key) {
      if (graph[idx].left == -1) {
        graph[cnt] = (Node){key, -1, -1};
        graph[idx].left = cnt;
        return idx;
      }
      idx = graph[idx].left;
    }
  }
}

void postorder(Node tree[], int idx) {
  if (idx == -1) return;
  postorder(tree, tree[idx].left);
  postorder(tree, tree[idx].right);
  printf("%d\n", tree[idx].vertex);
}

int main(void) {
  int n, cnt = 0;
  Node graph[10000];
  while (scanf("%d", &n) != EOF) {
    int idx = search(graph, n, cnt);
    cnt++;
  }

  postorder(graph, 0);
  return 0;
}
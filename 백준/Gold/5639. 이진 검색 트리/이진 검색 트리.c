#include <stdio.h>

typedef struct {
  int vertex;
  int left, right;
} Node;

Node create_node(int key) {
  return (Node){key, -1, -1};
}

void push(Node graph[], int key, int len) {
  if (len == 0) {
    graph[0] = create_node(key);
    return;
  }
  int idx = 0;
  while (1) {
    if (graph[idx].vertex < key) {
      if (graph[idx].right == -1) {
        graph[len] = create_node(key);
        graph[idx].right = len;
        return;
      }
      idx = graph[idx].right;
    }else if (graph[idx].vertex > key) {
      if (graph[idx].left == -1) {
        graph[len] = create_node(key);
        graph[idx].left = len;
        return;
      }
      idx = graph[idx].left;
    }
  }
}

void postorder(Node graph[], int idx) {
  if (idx == -1) return;
  postorder(graph, graph[idx].left);
  postorder(graph, graph[idx].right);
  printf("%d\n", graph[idx].vertex);
}

int main(void) {
  int n, len = 0;
  Node graph[10000];
  while (scanf("%d", &n) != EOF) {
    push(graph, n, len);
    len++;
  }

  postorder(graph, 0);

  return 0;
}
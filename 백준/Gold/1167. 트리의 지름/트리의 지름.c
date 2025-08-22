#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
  int vertex;
  int cost;
  struct Node* next;
} Node;

Node* createNode(int vertex, int cost) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->vertex = vertex;
  node->cost = cost;
  node->next = NULL;
  return node;
}

void pushNode(Node **head, int vertex, int cost) {
  Node* newNode = createNode(vertex, cost);
  newNode->next = *head;
  *head = newNode;
}

Node* findNode(Node* node, int vertex) {
  Node* current = node;
  while (current != NULL) {
    if (current->vertex == vertex) {
      return current;
    }else {
      current = current->next;
    }
  }
  return NULL;
}

void dfs(Node* node[], int idx, int length, int* maxv, char visited[], int* maxNode) {
  visited[idx] = 1;

  if (length > *maxv) {
    *maxv = length;
    *maxNode = idx;
  }
  Node *current = node[idx];
  while (current != NULL) {
    int vertex = current->vertex;
    int cost = current->cost;
    if (!visited[vertex]) {
      dfs(node, vertex, length+cost, maxv, visited, maxNode);
    }
    current = current->next;
  }
}

int main(void) {
  int v, node, next, cost;
  char visited[100001]={0};
  Node* nodes[100001] = {NULL};
  scanf("%d", &v);
  for (int i = 0; i < v; i++) {
    scanf("%d", &node);
    while (1) {
      scanf("%d", &next);
      if (next == -1) break;
      scanf("%d", &cost);
      pushNode(&nodes[node], next, cost);
      pushNode(&nodes[next], node, cost);
    }
  }

  int maxv = 0;
  int maxNode = 1;
  dfs(nodes, maxNode, 0, &maxv, visited, &maxNode);

  memset(visited, 0, sizeof(visited));
  maxv = 0;
  dfs(nodes, maxNode, 0, &maxv, visited, &maxNode);

  printf("%d\n", maxv);
  return 0;
}
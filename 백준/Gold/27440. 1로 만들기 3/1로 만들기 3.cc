#include <stdio.h>
#define HASH_SIZE 20000000

typedef struct {
  long long key;
  char used;
} HashNode;

HashNode visited[HASH_SIZE];
long long int queue[10000000][2];

void mark_visited(long long x) {
  int h = (x % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
  while (visited[h].used) {
    if (visited[h].key == x) return;
    h = (h + 1) % HASH_SIZE;
  }
  visited[h].key = x;
  visited[h].used = 1;
}

char is_visited(long long x) {
  int h = (x % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
  while (visited[h].used) {
    if (visited[h].key == x) return 1;
    h = (h + 1) % HASH_SIZE;
  }
  return 0;
}

int main(void) {
  int minv = 1000000000;
  int top = 0, bottom = 0;
  scanf("%lld", &queue[top][0]);
  queue[top++][1] = 0;
  while (bottom < top) {
    const long long int x = queue[bottom][0];
    int t = (int)queue[bottom++][1];
    if (minv < t) continue;
    if (x == 1) {
      if (minv > t) minv = t;
    }else {
      if (x%3 == 0 && !is_visited(x/3)) {
        queue[top][0] = x/3;
        queue[top++][1] = t+1;
        mark_visited(x/3);
      }
      if (x%2 == 0 && !is_visited(x/2)) {
        queue[top][0] = x/2;
        queue[top++][1] = t+1;
        mark_visited(x/2);
      }
      if (x > 1 && !is_visited(x-1)) {
        queue[top][0] = x-1;
        queue[top++][1] = t+1;
        mark_visited(x-1);
      }
    }
  }
  printf("%d\n", minv);
  return 0;
}
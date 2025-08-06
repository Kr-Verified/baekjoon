#include <stdio.h>
#include <stdlib.h>
#define MAX 5000000

int arr[MAX];
int deque[MAX];
int front = 0, rear = -1;

void push_back(int value) {
  deque[++rear] = value;
}

int front_val() {
  return deque[front];
}

int back_val() {
  return deque[rear];
}

int main(void) {
  int n, l;
  scanf("%d %d", &n, &l);

  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

  for (int i = 0; i < n; i++) {
    while (front <= rear && arr[back_val()] >= arr[i]) rear--;

    push_back(i);

    while (front_val() <= i-l) front++;

    printf("%d ", arr[front_val()]);

  }

  return 0;
}
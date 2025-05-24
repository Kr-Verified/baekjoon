import sys
input = sys.stdin.readline

class MinHeap:
  def __init__(self):
    self.heap = [0]
  def push(self, x):
    self.heap.append(x)
    i = len(self.heap) -1
    while i>1 and self.heap[i] < self.heap[i//2]:
      self.heap[i], self.heap[i//2] = self.heap[i//2], self.heap[i]
      i //= 2
  
  def pop(self):
    if len(self.heap) <= 1:
      return 0
    if len(self.heap) == 2:
      return self.heap.pop()
    
    root = self.heap[1]
    self.heap[1] = self.heap.pop()
    i = 1

    while True:
      left = i*2
      right = left+1
      smallest = i

      if left < len(self.heap) and self.heap[left] < self.heap[smallest]:
        smallest = left
      if right < len(self.heap) and self.heap[right] < self.heap[smallest]:
        smallest = right
      if smallest == i:
        break

      self.heap[i], self.heap[smallest] = self.heap[smallest], self.heap[i]
      i = smallest
    return root
  
  def top(self):
    return self.heap[i] if len(self.heap) > 1 else 0

heap = MinHeap()
for _ in range(int(input())):
  n = int(input())
  if n==0:
    print(heap.pop())
  else:
    heap.push(n)
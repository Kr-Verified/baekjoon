from collections import deque
n = int(input())
graph = {i:() for i in range(n)}
for _ in range(n):
  n, l, r = map(lambda x:ord(x)-65 if x!='.' else -1, input().split())
  graph[n] = (l, r)

def preorder(node):
  if node==-1:
    return
  sequence.append(chr(node+65))
  preorder(graph[node][0])
  preorder(graph[node][1])

def inorder(node):
  if node==-1:
    return
  inorder(graph[node][0])
  sequence.append(chr(node+65))
  inorder(graph[node][1])

def postorder(node):
  if node==-1:
    return
  postorder(graph[node][0])
  postorder(graph[node][1])
  sequence.append(chr(node+65))


sequence = []
preorder(0)
print(''.join(sequence))
sequence = []
inorder(0)
print(''.join(sequence))
sequence = []
postorder(0)
print(''.join(sequence))
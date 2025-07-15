string = input()
priority = {"+":1, "-":1, "*":2, "/":2}
alpha = []
oper = []

for token in string:
  if token.isalpha():
    alpha.append(token)
  elif token == "(":
    oper.append(token)
  elif token == ")":
    while oper and oper[-1] != "(":
      alpha.append(oper.pop())
    oper.pop()
  else:
    while oper and oper[-1] != "(" and priority[oper[-1]] >= priority[token]:
      alpha.append(oper.pop())
    oper.append(token)

while oper:
  alpha.append(oper.pop())

print("".join(alpha))
strings = list({input() for _ in range(int(input()))})

strings.sort(key=lambda x: (len(x), x))

for string in strings:
  print(string)
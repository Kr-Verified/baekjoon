import sys

lines = []
while True:
    line = sys.stdin.readline()
    if not line: break
    while "BUG" in line:
        line = line.replace("BUG", "")
    lines.append(line)
print(''.join(lines))
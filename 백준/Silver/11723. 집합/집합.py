import sys
input = sys.stdin.readline

s = 0  # 빈 집합: 0으로 초기화 (비트 0 모두 꺼짐)

for _ in range(int(input())):
    command, *rest = input().split()
    
    if rest:
        x = int(rest[0]) - 1  # 0-based index (1~20 → 0~19)
    
    if command == "add":
        s |= (1 << x)  # x번째 비트 켜기
    elif command == "remove":
        s &= ~(1 << x) # x번째 비트 끄기
    elif command == "check":
        print(1 if s & (1 << x) else 0)  # x번째 비트가 켜져 있으면 1 아니면 0
    elif command == "toggle":
        s ^= (1 << x)  # x번째 비트 토글
    elif command == "all":
        s = (1 << 20) - 1  # 20개의 비트를 모두 1로 (모든 원소 포함)
    elif command == "empty":
        s = 0  # 빈 집합
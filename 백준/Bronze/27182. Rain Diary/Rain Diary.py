# 입력 받기
n, m = map(int, input().split())

# 2주 전 기록과 현재 날짜 차이로 한 달 길이 추정
# 2주(14일) 전 기록이므로, (n - m) + 14가 한 달 길이의 배수일 수 있음
# 한 달 길이 후보군: 28, 29, 30, 31 중 하나를 찾음

possible_month_lengths = [28, 29, 30, 31]
month_length = 28  # 기본값

for length in possible_month_lengths:
    # (n - m) mod length가 14와 같으면 length가 맞는 달 길이
    if (n - m) % length == 14 % length:
        month_length = length
        break

# 지난 일요일 날짜 계산
last_sunday = n - 7
if last_sunday <= 0:
    last_sunday += month_length

print(last_sunday)

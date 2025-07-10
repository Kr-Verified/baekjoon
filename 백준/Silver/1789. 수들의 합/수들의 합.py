n = int(input())
cnt = 0
while True:
    if n > cnt: # n이 i보다 크면 n에 i를 차감
        cnt += 1
        n = n-cnt
    else:
        print(cnt)
        break
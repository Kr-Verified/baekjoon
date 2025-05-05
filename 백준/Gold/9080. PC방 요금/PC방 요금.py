for _ in range(int(input())):
  time_str, play = input().split()
  h, m = map(int, time_str.split(':'))
  current_time, play, pay = h * 60 + m, int(play), 0

  while play > 0:
    if (1320 <= current_time or current_time <= 180) and play >= 300:
      duration = 480-current_time if current_time<=180 else 1920-current_time
      current_time = (current_time + min(play, duration)) % 1440
      play -= min(play, duration)
      pay += 5000
    else:
      play -= 60
      current_time = (current_time + 60) % 1440
      pay += 1000
  print(pay)

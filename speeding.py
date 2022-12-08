n = int(input())

max_speed = 0
last_time = 0
last_dist = 0

for _ in range(n):
    time, dist = map(int, input().split(' '))
    if time - last_time != 0:
        speed = (dist-last_dist) // (time-last_time)
        if speed > max_speed: max_speed = speed

    last_dist = dist
    last_time = time
    
print(max_speed)

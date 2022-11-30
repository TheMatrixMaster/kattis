n = int(input())

longitudes = []

possible = False
touched = [False] * 720

for _ in range(n):
    lat, long = map(int, input().split(' '))
    longitudes.append(long)

for i in range(len(longitudes)):
    cur = longitudes[i % len(longitudes)]
    next = longitudes[(i+1) % len(longitudes)]

    if abs(next - cur) == 180:
        possible = True
        break
    elif abs(next - cur) < 180:
        cur = 2*(cur+180)
        next = 2*(next+180)

        for j in range(min(cur, next), max(cur, next)+1):
            touched[j] = True
    else:
        cur = 2*(cur+180)
        next = 2*(next+180)

        for j in range(0, min(cur, next)+1):
            touched[j] = True

        for j in range(max(cur, next), 720):
            touched[j] = True


if possible or all(touched): print('yes')
else:
    index = (touched.index(False) / 2) - 180
    print(f'no {index}')
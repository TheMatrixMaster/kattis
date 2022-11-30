l, k, s = map(int, input().split(' '))

r = [[0, 0, 0] for _ in range(s)]

for _ in range(l):
    id, time = input().split(' ')
    mm, ss = map(int, time.split('.'))
    r[int(id)-1][0] += (mm*60 + ss)
    r[int(id)-1][1] += 1
    r[int(id)-1][2] = int(id)

for index, [time, laps, _] in enumerate(r):
    if laps != k:
        r[index] = [-1, -1, -1]

r = sorted(r, key=lambda x: x[0])

for i, [time, laps, id] in enumerate(r):
    if time != -1:
        print(id)
        r[i][0] = -1
        
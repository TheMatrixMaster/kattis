s, t, n = map(int, input().split(' '))

d = list(map(int, input().split(' ')))

b = list(map(int, input().split(' ')))

c = list(map(int, input().split(' ')))

time = s

for i in range(n):
    time += d[i]

    if time < c[i]: time += (c[i] - time)
    elif time % c[i] != 0:
        time += (c[i] - (time % c[i]))

    time += b[i]

    # print(i, time)
    
time += d[-1]

# print(time)

if time <= t: print('yes')
else: print('no')
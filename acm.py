from collections import Counter


raw = input()
d = Counter()

n, s = 0, 0

while raw != '-1':

    t, l, res = raw.split(' ')

    if res[0] == 'w':
        d[l] += 20

    elif res[0] == 'r':
        n += 1
        s += (int(t) + d[l])

    raw = input()

print(n, s)
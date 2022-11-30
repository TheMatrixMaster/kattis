def transform(arr):
    arr = list(arr)
    p = []
    f = []
    m = False
    for val in reversed(arr):
        if val == 0:
            p.append(0)
        elif m and val == f[0]:
            f[0] = 2*val
            p.append(0)
            m = False
        else:
            f.insert(0, val)
            m = True
            
    return p + f

n = []

for i in range(4):
    row = list(map(int, input().split(' ')))
    n.append(row)

move = int(input())

if move == 0:
    n = list(map(reversed, map(transform, map(reversed, n))))
elif move == 1:
    n = list(zip(*map(reversed, map(transform, map(reversed, list(zip(*n)))))))
elif move == 2:
    n = list(map(transform, n))
elif move == 3:
    n = list(zip(*map(transform, list(zip(*n)))))

for row in n:
    print(*row, sep=' ')

r, c = map(int, input().split(' '))

m = []

for _ in range(r):
    m.append([int(c) for c in input().strip()])


# Start finding connected components on map

ss = {(i, j) for i in range(r) for j in range(c)}

def mark(map, start, flag):
    s = [start]

    s1, s2 = start
    target = map[s1][s2]

    while s:
        x, y = s.pop()
        ss.discard((x, y))
        map[x][y] = f"{chr(flag)}{target}"

        # left, top, right, bottom
        for nx, ny in [(x, y-1), (x-1, y), (x, y+1), (x+1, y)]:
            if r > nx >= 0 and c > ny >= 0 and map[nx][ny] == target:
                s.append((nx, ny))

    return map

flag = 0

while ss:
    m = mark(m, ss.pop(), flag)
    flag += 1

n = int(input())

for _ in range(n):
    r1, c1, r2, c2 = map(int, input().split(' '))
    start = m[r1-1][c1-1]
    end = m[r2-1][c2-1]
    
    if start == end:
        if start[-1] == '1':
            print('decimal')
        else:
            print('binary')
    else:
        print('neither')

    
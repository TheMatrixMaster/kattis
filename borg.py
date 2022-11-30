n = int(input())

def bfs(m, start: tuple):
    q = [start]
    step = 0

    while q:
        x, y = q.pop(0)
        

for _ in range(n):
    x, y = map(int, input().split(' '))

    count = 0
    m = []
    start = None

    for i in range(y):
        raw = input()
        row = []

        for j, c in enumerate(raw):
            if c == 'A':
                row.append(count)
                count += 1
            elif c == 'S':
                row.append(count)
                count += 1
                start = (i, j)
            else:
                row.append(c)

        m.append(row)

    for row in m:
        print(row)

    distances = [[0] * count for i in range(count)]

    print(distances)

n = int(input())

xy = (0, 0, 0)
x_y = (0, 0, 0)
_xy = (0, 0, 0)
_x_y = (0, 0, 0)

if n == 1: print(4)
else:
    for _ in range(n):
        x, y = map(int, input().split(' '))
        if x+y > xy[-1]: xy = (x, y, x+y)
        if x-y > x_y[-1]: x_y = (x, y, x-y)
        if -x+y > _xy[-1]: _xy = (x, y, -x+y)
        if -x-y > _x_y[-1]: _x_y = (x, y, -x-y)

    l = [z for (x, y, z) in list(set([xy, x_y, _x_y, _xy]))]
    
    print(l)
    # print(xy+x_y+_xy+_x_y + len(l))


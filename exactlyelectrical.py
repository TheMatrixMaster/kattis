x1, y1 = map(int, input().split(' '))
x2, y2 = map(int, input().split(' '))
c = int(input())

initial = abs(y2-y1)+abs(x2-x1)

if c < initial: print('N')
elif c == initial: print('Y')
elif (c-initial)%2 == 1: print('N')
else: print('Y')

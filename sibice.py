import math

n, w, h = map(int, input().split(' '))

max = math.sqrt(w**2 + h**2)

for _ in range(n):
    
    l = int(input())
    
    if l <= max:
        print('DA')
    else:
        print('NE')
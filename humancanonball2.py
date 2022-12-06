from math import cos, sin, pi

n = int(input())
out = []

for _ in range(n):
    
    v, a, x, h1, h2 = map(float, input().split(' '))
    a = a * pi / 180
    
    t = x / v / cos(a)
    
    hy = v * t * sin(a) - 0.5 * 9.81 * t**2
    
    if hy >= h1+1 and hy <= h2-1:
        out.append((hy, "Safe"))
    else:
        out.append((hy, "Not Safe"))

for hy, o in out:
    print(o)
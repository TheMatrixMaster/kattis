from math import pi

r, m, c = map(float, input().split(' '))

while r != 0 or m != 0 or c != 0:
    
    true = pi * r**2
    
    est = (c/m) * (2*r)**2
    
    print(true, est)

    r, m, c = map(float, input().split(' '))
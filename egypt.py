a, b, c = map(int, input().split(' '))

while a!=0 or b!=0 or c!=0:

    a, b, c = sorted([a, b, c])
    
    if a**2 + b**2 == c**2:
        print('right')
    else:
        print('wrong')
    
    a, b, c = map(int, input().split(' '))
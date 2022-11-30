x, y, n = map(int, input().split(' '))

for v in range(1, n+1):
    w = ''
    
    if v % x == 0:
        w += 'Fizz'
        
    if v % y == 0:
        w += 'Buzz'
        
    if w == '':
        print(v)
    else:
        print(w)
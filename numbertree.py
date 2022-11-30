h, path = input().split(' ')

r = (2**(int(h)+1))-1

prev = 0
prevdir = ''

while path:
    dir = path[0]
    
    if dir == prevdir:
        prev = 2*prev

    elif prevdir == 'L':
        prev = 2*prev + 1

    elif prevdir == 'R':
        prev = 2*prev - 1

    else:
        prev = 1 if dir == 'L' else 2

    prevdir = dir
    r -= prev 
    
    path = path[1:]
    
print(r)
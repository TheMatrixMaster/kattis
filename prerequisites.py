

line = input()

while line != '0':
    
    ok = True
    k, m = map(int, line.split(' '))
    
    courses = list(map(int, input().split(' ')))
    
    for _ in range(m):
        
        raw = list(map(int, input().split(' ')))
        num = raw.pop(0)
        minc = raw.pop(0)
        taken = [c for c in raw if c in courses]
        
        if len(taken) < minc:
            ok = False
            
    print('yes' if ok else 'no')
    
    line = input()
    
    
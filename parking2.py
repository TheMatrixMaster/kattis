from math import inf

t = int(input())

for _ in range(t):
    
    n = int(input())
    
    pos = sorted(list(map(int, input().split(' '))))
    sm = pos[0]
    lg = pos[-1]
    
    optimal = inf
    
    for start in range(0, 101):
    
        if sm < start: left = start - sm
        else: left = 0

        if lg > start: right = lg - start
        else: right = 0
        
        tot = 2*left + 2*right
        
        if tot < optimal:
            optimal = tot
            
    print(optimal)
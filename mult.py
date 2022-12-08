n = int(input())

s = -1

for _ in range(n-1):
    
    c = int(input())
    
    if s == -1: 
        s = c
        continue
    
    if c % s == 0:
        print(c)
        s = -1
    
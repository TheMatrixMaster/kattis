t = int(input())

for _ in range(t):
    imported = 0
    turtles = list(map(int, input().split(' ')))
    
    for i, t in enumerate(turtles[:-1]):
        lb = 2*t
        next = turtles[i+1]
        if next > lb:
            imported += (next - lb)
            
    print(imported)
    
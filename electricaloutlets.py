n = int(input())

for _ in range(n):
    
    outlets = list(map(int, input().split(' ')))
    k = outlets.pop(0)
    
    open = 1
    
    for outlet in sorted(outlets):
        open += (outlet)
        open -= 1
        
    print(open)
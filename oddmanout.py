n = int(input())

for i in range(n):
    s = set()
    g = int(input())
    
    for id in list(map(int, input().split(' '))):
        
        if id in s: s.remove(id)
        else: s.add(id)
        
    print(f"Case #{i+1}: {s.pop()}")
    
    
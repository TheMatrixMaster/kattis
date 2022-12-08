n = int(input())

r = []

for _ in range(n):
    
    a, b = input().split(' ')
    
    if a.isnumeric():
        r.append((b, int(a)//2))
    else:
        r.append((a, int(b)))
        
r = sorted(r, key=lambda x: x[1])

for k in r:
    print(k[0])
        
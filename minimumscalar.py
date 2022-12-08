t = int(input())

for i in range(t):
    
    n = int(input())
    
    fir = sorted(list(map(int, input().split(' '))))
    las = sorted(list(map(int, input().split(' '))), reverse=True)
    
    res = sum([a*b for a, b in zip(fir, las)])
    
    print(f"Case #{i+1}:", res)
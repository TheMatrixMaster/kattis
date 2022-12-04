p = int(input())

for _ in range(p):
    
    K, N = map(int, input().split(' '))
    
    s = sum([x+2 for x in range(N)])
    
    print(K, s)
t = int(input())

for _ in range(t):
    
    _ = input()
    
    NCS, NE = map(int, input().split(' '))
    
    cs = list(map(int, input().split(' ')))
    econ = list(map(int, input().split(' ')))
    
    avgcs = sum(cs) / len(cs)
    avgecon = sum(econ) / len(econ)
    
    r = [c for c in cs if c < avgcs and c > avgecon]
    
    print(len(r))
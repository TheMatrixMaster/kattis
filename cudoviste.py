from collections import Counter

r, c = map(int, input().split(' '))

m = []

for i in range(r):
    m.append(list(str(input())))
    
result = [0] * 5
    
for row in range(r-1):
    for col in range(c-1):
        
        tl = m[row][col]
        tr = m[row][col+1]
        bl = m[row+1][col]
        br = m[row+1][col+1]
        
        d = Counter([tl, bl, tr, br])
        
        if d['#'] > 0: continue
        elif d['X'] > 0:
            result[d['X']] += 1
        elif d['.'] == 4:
            result[0] += 1
            
    
for r in result:
    print(r)
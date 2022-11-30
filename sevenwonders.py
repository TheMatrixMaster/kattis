from collections import Counter

c = Counter(input())
r = 0

for k, v in c.items():
    r += v**2
    
while len(c) == 3:
    r += 7
    c = c - Counter('TCG')
    
print(r)

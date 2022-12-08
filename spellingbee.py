from collections import Counter

allowed = str(input())
center = allowed[0]
allowed = set(allowed)
res = []

n = int(input())

for _ in range(n):
    s = input()
    letters = set(s)
    
    if len(s) >= 4:
        if center in letters:
            if letters.issubset(allowed):
                res.append(s)


for r in res:
    print(r)
    
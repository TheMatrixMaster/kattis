from collections import Counter

s = input()
c = Counter(s)

to_remove = 0
used_odd = False

for l, count in c.items():
    if count % 2 == 0: continue
    elif count % 2 == 1:
        if used_odd: to_remove += 1
        else: used_odd = True
        
print(to_remove)
        

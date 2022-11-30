n = int(input())
ns = list(map(int, input().split(' ')))

s = set()
t = set()

for v in ns:
    if v in t: continue
    if v in s:
        s.remove(v)
        t.add(v)
    else:
        s.add(v)

if s:
    m = sorted(list(s))[-1]
    print(ns.index(m)+1)
else:
    print('none')

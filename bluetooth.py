import re

n = int(input())

d = {
    '+%': set(range(1, 9)),
    '-%': set(range(1, 9)),
    '%+': set(range(1, 9)),
    '%-': set(range(1, 9)),
}

for _ in range(n):
    
    prob, type = input().split(' ')
    
    key = re.sub('\d', '%', prob)
    val = re.sub("[^0-9]", "", prob)
    
    if type == 'b':
        d[key].clear()
    else:
        d[key].remove(int(val))
    
if d['+%'] and d['-%']: print(0)
elif d['%+'] and d['%-']: print(1)
else: print(2)
n = int(input())

correct = str(input())

adrian = ['A', 'B', 'C']
bruno = ['B', 'A', 'B', 'C']
goran = ['C', 'C', 'A', 'A', 'B', 'B']

ca = 0
cb = 0
cg = 0

for i, c in enumerate(correct):
    
    if adrian[i%3] == c: ca += 1
    if bruno[i%4] == c: cb += 1
    if goran[i%6] == c: cg += 1
    
winner = max(ca, cb, cg)
print(winner)

if winner == ca: print('Adrian')
if winner == cb: print('Bruno')
if winner == cg: print('Goran')
    
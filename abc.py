n = sorted(map(int, input().strip().split(' ')))
d = { 'A': n[0], 'B': n[1], 'C': n[2] }
l = input()

r = ''

for c in l:
    r += str(d[c]) + ' '

print(r[:-1])

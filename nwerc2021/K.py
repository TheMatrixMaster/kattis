from collections import Counter

n = int(input())

independent = 0
possible = False

c = Counter()

for _ in range(n):
    i, j, k = input().split(' ')
    k = int(k)

    if i in c:
        possible = True

    if j == 'any':
        if k > 1: 
            possible = True
        k = 1

    if k > c[i]: c[i] = k

if possible:
    print(sum(c.values())+1)
else:
    print('impossible')

    
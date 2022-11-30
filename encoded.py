n = int(input())

g = []

for _ in range(n):
    
    word = input()
    
    l = int(len(word)**0.5)
    
    m = [['']*l for _ in range(l)]
    
    for i in range(l):
        for j in range(l):
            m[i][j] = word[(i*l)+j]

    goodword = ''

    for row in reversed(list(zip(*m))):
        goodword += ''.join(row)

    g.append(goodword)


for w in g:
    print(w)
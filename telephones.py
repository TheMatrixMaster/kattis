n, m = map(int, input().split(' '))

out = []

while n != 0 and m != 0:

    book = []

    for _ in range(n):
        s, d, start, duration = map(int, input().split(' '))
        book.append((start, start+duration))
        
    for _ in range(m):
        res = 0
        i1, i2 = map(int, input().split(' '))
        i2 += i1
        
        for (start, end) in book:
            if start >= i2 or end <= i1: continue
            else: res += 1

        out.append(res)

    n, m = map(int, input().split(' '))
    

for o in out:
    print(o)
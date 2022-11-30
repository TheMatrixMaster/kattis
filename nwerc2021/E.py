n = int(input())

curr = list(map(int, input().split(' ')))
tar = list(map(int, input().split(' ')))

iarr = [x for x in range(1, n+1)]

c = 0
res = []

while curr:
    print()
    print(curr)
    m = min(curr)

    i = len(curr) - curr[::-1].index(m) - 1
    j = len(tar) - tar[::-1].index(m) - 1

    print(m, i, j, iarr)

    if i != j:
        r = [x for x in iarr[i:j+1] if x != -1]
        c += len(r)-1
        res.append(r)

        print(r)

    iarr[j] = -1
    tar[j] = -1
    curr.pop(i)

# print(c)

# c = 200000

# for r in res:
#     if c <= 0: break
#     for i in range(len(r)-1):
#         print(r[i], r[i+1])
#         c -= 1
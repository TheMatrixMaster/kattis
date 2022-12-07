n = int(input())

if n == 1:
    print(1)
else:
    ds = list(map(int, input().split(' ')))

    orig = [0] * n
    orig[0] = 1

    for i, d in enumerate(ds):
        
        orig[d+1] = i+2
        
    print(" ".join(map(str, orig)))
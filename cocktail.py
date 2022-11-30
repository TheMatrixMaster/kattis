n, m = map(int, input().split(' '))

t = sorted([int(input()) for i in range(n)], reverse=True)

f = True

for i, v in enumerate(t):
    if v <= ((n-(i+1))*m):
        f = False
    

if f:
    print("YES")
else:
    print("NO")
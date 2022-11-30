n = int(input().strip())

res = 0.0

for _ in range(n):
    n, q = map(float, input().split(' '))
    res += (n * q)
    
print(round(res, 3))
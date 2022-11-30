n = int(input())

r = [0] * max(n+1, 4)

r[1] = 1
r[2] = 2
r[3] = 4

for i in range(4, n+1):
    r[i] =  r[i-1] + r[i-2] + r[i-3]
    
print(r[n])
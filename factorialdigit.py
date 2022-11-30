n = int(input())

d = {}
s = 1

for i in range(1, 11):
    t = s*i
    d[i] = t % 10
    s = t

for _ in range(n):
    print(d[int(input())])
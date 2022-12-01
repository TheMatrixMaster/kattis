n = int(input())

A = list(map(int, input().split(' ')))

pass1 = [False] * len(A)
pass2 = [False] * len(A)

p1max = -1
p2min = 2**31

for i, n in enumerate(A):
    if n > p1max:
        pass1[i] = True
        p1max = n
        

for i in range(len(A)-1, -1, -1):
    if A[i] < p2min:
        pass2[i] = True
        p2min = A[i]

r = 0        

for p1, p2 in zip(pass1, pass2):
    if p1 == p2 == True:
        r += 1
        
print(r)
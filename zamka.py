L = int(input())
D = int(input())
X = int(input())

def sum_of_digits(n):
    return sum(map(int, list(str(n))))

for i in range(L, D+1):
    if sum_of_digits(i) == X:
        print(i)
        break
    
for j in range(D, L-1, -1):
    if sum_of_digits(j) == X:
        print(j)
        break
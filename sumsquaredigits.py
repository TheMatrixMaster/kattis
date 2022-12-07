p = int(input())

def numberToBase(n, b):
    if n == 0:
        return [0]
    digits = []
    while n:
        digits.append(int(n % b))
        n //= b
    return digits[::-1]

for _ in range(p):
    
    K, b, n = map(int, input().split(' '))
    
    digits = numberToBase(n, b)
    
    ssd = sum([d**2 for d in digits])
    
    print(K, ssd)
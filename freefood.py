n = int(input())

days = [0] * 365

for _ in range(n):
    a, b = map(int, input().split(' '))
    
    for i in range(a, b+1):
        days[i-1] = 1
        
print(days.count(1))
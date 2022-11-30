n = int(input())

l = [x for x in map(int, input().split(' ')) if x != 0]
        
sum = 0
acc = 0
best = 0
        
for i, v in enumerate(reversed(l)):
    acc += v
    sum += (len(l)-i)*v
    
    if acc > best:
        best = acc

print(best+sum)
    
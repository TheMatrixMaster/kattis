from bisect import bisect_left

p = int(input())
m = []

for i in range(1, p+1):
    right = int(input())
    
    if not m or right > m[-1]:
        m.append(right)
    else:
        pos = bisect_left(m, right)
        m[pos] = right    

print(len(m))
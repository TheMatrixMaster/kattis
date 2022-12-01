from math import inf

n = int(input())

runners = []

for _ in range(n):
    
    name, a, b = input().split(' ')
    
    runners.append((name, float(a), float(b)))
    
leg1sorted = sorted(runners, key=lambda x: x[1])
leg2sorted = sorted(runners, key=lambda x: x[2])

leg1index = 0
leg2final = []

time = inf

for i, (run1, leg1, _) in enumerate(leg1sorted):
    
    leg2runners = [r for r in leg2sorted if r[0] != run1][:3]
    newtime = leg1 + sum([x[2] for x in leg2runners])

    if newtime < time:
        time = newtime
        leg1index = i
        leg2final = leg2runners 

print(time)
print(leg1sorted[leg1index][0])
print(leg2final[0][0])
print(leg2final[1][0])
print(leg2final[2][0])

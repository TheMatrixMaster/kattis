a1, b1, a2, b2 = map(int, input().split(' '))

c1, d1, c2, d2 = map(int, input().split(' '))

avg1 = sum(range(a1, b1+1))/(b1-a1+1) + sum(range(a2, b2+1))/(b2-a2+1)
avg2 = sum(range(c1, d1+1))/(d1-c1+1) + sum(range(c2, d2+1))/(d2-c2+1)

if avg1 > avg2: print('Gunnar')
elif avg2 > avg1: print('Emma')
else: print('Tie')
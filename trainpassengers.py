C, n = map(int, input().split(' '))

cap = 0
possible = True
waited = 0

for i in range(n):
    
    left, entered, waited = map(int, input().split(' '))

    if left > cap:
        possible = False
        break
    else:
        cap -= left
    
    if cap + entered > C:
        possible = False
        break
    else:
        cap += entered
        
    if cap < C and waited > 0:
        possible = False
        break
    
if cap != 0 or waited != 0: possible = False

if possible: print('possible')
else: print('impossible')
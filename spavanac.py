h, m = map(int, input().split(' '))

nh, nm = h, m - 45

if nm < 0:
    nm = 60 + nm
    nh = 23 if nh == 0 else nh-1
    
print(nh, nm)
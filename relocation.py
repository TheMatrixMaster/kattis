n, q = map(int, input().split(' '))

locations = list(map(int, input().split(' ')))

for _ in range(q):
    
    cmd, a, b = input().split(' ')
    
    if cmd == '1':
        locations[int(a)-1] = int(b)
        
    elif cmd == '2':
        la = locations[int(a)-1]
        lb = locations[int(b)-1]
        print(abs(la-lb))
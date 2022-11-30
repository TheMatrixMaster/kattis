n = int(input())

out = []

for _ in range(n):
    
    fir = input()
    las = input()
    
    diff = ['.' if ord(c1)==ord(c2) else '*' for c1, c2 in zip(fir, las)]
    
    out.extend([fir, las, ''.join(diff), ''])

for line in out:
    print(line)
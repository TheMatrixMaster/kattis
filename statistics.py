from sys import stdin

lines = stdin.read().splitlines()

i=1

for line in lines:
    
    raw = list(map(int, line.split(' ')))
    raw.pop(0)
    
    maximum = max(raw)
    minimum = min(raw)
    range = maximum - minimum
    
    print(f'Case {i}:', minimum, maximum, range)

    i+=1


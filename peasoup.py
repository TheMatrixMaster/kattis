n = int(input())

valid = []

for _ in range(n):
    k = int(input())
    name = str(input())
    
    peasoup = False
    pancakes = False
    
    for _ in range(k):
        item = str(input())
        if item == 'pea soup':
            peasoup = True
        elif item == 'pancakes':
            pancakes = True
            
    if peasoup and pancakes:
        valid.append(name)
        
if valid:
    print(valid[0])
else:
    print("Anywhere is fine I guess")
        
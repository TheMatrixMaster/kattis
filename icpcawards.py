n = int(input())

awarded = set()

for _ in range(n):
    
    school, name = input().split(' ')
    
    if len(awarded) == 12:
        continue
    
    if school not in awarded:
        awarded.add(school)
        print(school, name)
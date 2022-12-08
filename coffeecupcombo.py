n = int(input())

l = list(map(int, list(input())))

c = 0
coffees = 0
for i, cl in enumerate(l):
    if cl == 1:
        c += 1
        if coffees < 2: coffees = 2
    elif cl == 0:
        if coffees > 0:
            coffees -= 1
            c += 1
            
print(c)
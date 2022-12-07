f = str(input())
s = str(input())


poss = 1

for a, b in zip(f, s):
    if a != b:
        poss *= 2
        
print(poss)
e, f, c = map(int, input().split(' '))

empty = e+f
full = 0

while empty >= c:
    new_full = empty // c
    left_empty = empty % c
    full += new_full
    empty = new_full + left_empty
    
print(full)
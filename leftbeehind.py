n, m = map(int, input().split(' '))

while n != 0 or m != 0:
    
    if n+m == 13: print("Never speak again.")
    elif n == m: print("Undecided.")
    elif n > m: print("To the convention.")
    else: print("Left beehind.")
    
    n, m = map(int, input().split(' '))

    
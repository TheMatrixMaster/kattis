n = int(input())

if n < 100:
    print(99)

else:
    base = n % 100
    
    if base >= 49:
        print(n + (99 - base))

    else:
        print(n - (base + 1))
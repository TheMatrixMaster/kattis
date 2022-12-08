n = int(input())

found = False

while not found:
    
    digitsum = sum(list(map(int, list(str(n)))))
    
    if n % digitsum == 0:
        print(n)
        found = True
    else:
        n += 1
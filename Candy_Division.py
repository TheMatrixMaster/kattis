import math

def factorize(n):
    r = []
    for i in range(1, int(math.sqrt(n) + 1)):
        if n % i == 0:
            r.append(i)
            if n != i**2:
                r.append(n // i)

    r = sorted([x - 1 for x in r])

    out = ""
    for x in r:
        out += (str(x) + " ")

    print(out[:-1])

n = int(input())
factorize(n)

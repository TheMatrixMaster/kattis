import math
from collections import Counter

def sieve(num):
    prime = [True for i in range(num+1)]
    # boolean array
    p = 2
    while (p * p <= num):
  
        # If prime[p] is not
        # changed, then it is a prime
        if (prime[p] == True):
            # Updating all multiples of p
            for i in range(p * p, num+1, p):
                prime[i] = False

        p += 1
  
    return [p for p, v in enumerate(prime) if v][2:]


def dividible(n, p):
    i = 0
    while n % p==0:
        n /= p
        i += 1
    return i

def factorize(n, f):
    factors = Counter()
    while f:
        i = f.pop(0)
        # Check if i divides x without leaving a remainder
        if n % i == 0:
            factors[i] = dividible(n, i)
            # This means that n has a factor in between 2 and sqrt(n)
            # So it is not a prime number
            # return False

    return factors

if __name__ == '__main__':
    n = int(input())
    factors = sieve(math.floor(math.sqrt(n)))
    c = factorize(n, factors)
    s = sorted(c.most_common(2))
    
    if s: print(s[0][0])
    else: print(1)
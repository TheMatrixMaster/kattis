
def SieveOfEratosthenes(num):
    prime = [True for i in range(num+1)]
    # boolean array
    c = 0
    p = 2
    while (p * p <= num):
  
        # If prime[p] is not
        # changed, then it is a prime
        if (prime[p] == True):
            # Updating all multiples of p
            for i in range(p * p, num+1, p):
                prime[i] = False

        if (prime[p]): c += 1
        p += 1
  
    return prime, c


if __name__ == '__main__':
    n, q = map(int, input().split(' '))
    sieve, c = SieveOfEratosthenes(n)
    print(c)
    print(sieve.count(True)-2)
    for _ in range(q):
        i = int(input())
        if i == 1:
            print(0)
        else:
            print(1) if sieve[i] else print(0)

// C program to print all primes smaller than or equal to
// n using Sieve of Eratosthenes
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool* SieveOfEratosthenes(int n)
{

	// Create a boolean array "prime[0..n]" and initialize
	// all entries it as true. A value in prime[i] will
	// finally be false if i is Not a prime, else true.
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));

	for (int p = 2; p * p <= n; p++) {
		// If prime[p] is not changed, then it is a prime
		if (prime[p] == true) {
			// Update all multiples of p greater than or
			// equal to the square of it numbers which are
			// multiple of p and are less than p^2 are
			// already been marked.
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}

	int c = 0;
    for (int p = 2; p <= n; p++)
        if (prime[p]) c += 1;

	printf("%d\n", c);

	return prime;
}

// Driver Code
int main()
{
    int n, q, i, tmp;
    scanf("%d", &n);
    scanf("%d", &q);

	bool *sieve = SieveOfEratosthenes(n);

    for (i=0; i<q; i++) {
        scanf("%d", &tmp);
        if (tmp == 1) printf("%d\n", 0);
        else if (sieve[tmp]) printf("%d\n", 1);
        else printf("%d\n", 0);
    }

	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)

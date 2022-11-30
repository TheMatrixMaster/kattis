#include<iostream>

using namespace std;

int main()
{
	int n, q, i;
    cin >> n >> q;

	int t[q];

    for (i=0; i<q; i++) {
        cin >> t[i];
    }

	int c = 0;
	bool prime[n+1];
	
	for (i=0; i<n+1; i++) {
		prime[i] = true;
	}

	for (int p=2; p*p<=n; p++)
	{
		// If prime[p] is not changed, then it is a prime
		if (prime[p] == true)
		{
			// Update all multiples of p
			for (int i=p*2; i<=n; i += p)
				prime[i] = false;
		}
	}

	for (int p = 2; p <= n; p++)
        if (prime[p]) c += 1;

	cout << c << endl;

    for (int i=0; i<q; i++) {
		// cout << t[i] << endl;
		if (t[i] == 1) cout << 0 << endl;
		else if (prime[t[i]] == true) {
			cout << 1 << endl;
		}
		else cout << 0 << endl;
	}

	return 0;
}

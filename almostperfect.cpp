#include <iostream>
#include <cmath>

using namespace std;

int main() {
    size_t n, t;

    while (cin >> n) {
        t = 1;

        double sqr = sqrt(n);
        
        if (sqr == round(sqr)) {
            t += sqr;
        }
        for (int i = 2; i * i < n; i++) {
            if (n % i == 0) {
                t += i;
                t += (n / i);
            }
        }

        cout << n;
        
        if (n < t) {
            swap(t, n);
        }

        if (n - t > 2) {
            cout << " not";
        }
        else if (n - t) {
            cout << " almost";
        }
        cout << " perfect\n";
    }
    return 0;
}
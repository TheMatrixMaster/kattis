#include<iostream>

using namespace std;

int main()
{
    int t;
    long long candies;

    cin >> t;

    for (int i=0; i<t; i++) {
        cin.get();
        int n;
        int remainder = 0;
        cin >> n;

        for (int j=0; j<n; j++) {
            cin >> candies;
            remainder += candies % n;
        }

        if (remainder % n == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
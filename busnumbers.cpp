#include<iostream>
#include<string>

using namespace std;

int A[1050] = {0};

int main()
{
    int n, i, tmp;
    cin >> n;

    for (i=0; i<n; i++) {
        cin >> tmp;
        A[tmp] = 1;
    }
    
    int count = 0;
    int c;
    
    for (i=1; i<1050; i++) {
        if (A[i] == 1) {
            count += 1;
        } else {
            if (count == 1 | count == 2) {
                for (c=count; c>0; c--) {
                    cout << i-c << ' ';
                }
            } else if (count > 2) {
                cout << i-count << '-' << i-1 << ' ';
            }

            count = 0;
        }
    }
    cout << '\n';
    
    return 0;
}
#include<iostream>
#include<algorithm>
#include<string>
#include<set>
#include <stdint.h>

using namespace std;

int main() {
    int n, t;
    
    cin >> n >> t;
    
    int i;
    unsigned int arr[n];
    
    for (i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    switch (t) {
        case 1: {
            cout << 7 << endl;
            break;
        }

        case 2: {
            if (arr[0] > arr[1]) {
                cout << "Bigger" << endl;
            } else if (arr[0] == arr[1]) {
                cout << "Equal" << endl;
            } else {
                cout << "Smaller" << endl;
            }
            break;
        }

        case 3: {
            sort(&arr[0], &arr[3]);
            cout << arr[1] << endl;
            break;
        }

        case 4: {
            unsigned int sum = 0;
            for (unsigned int n : arr) sum += n;
            cout << sum << endl;
            break;
        }

        case 5: {
            unsigned int esum = 0;
            for (unsigned int n : arr) {
                if (n % 2 == 0) esum += n;
            }
            cout << esum << endl;
            break;
        }

        case 6: {
            char c;
            string s;
            for (unsigned int n : arr) {
                c = 'a' + (n % 26);
                s += c;
            }
            cout << s << endl;
            break;
        }

        case 7: {
            int i = 0;
            int visited[n];

            while (true) {
                if (i >= n) {
                    cout << "Out" << endl;
                    break;
                } 
                if (visited[i] == 1) {
                    cout << "Cyclic" << endl;
                    break;
                }
                if (i == n-1) {
                    cout << "Done" << endl;
                    break;
                }

                visited[i] = 1;
                i = arr[i];
            }
        }
    }
    
    
    return 0;
}
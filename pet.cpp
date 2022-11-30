#include<iostream>

using namespace std;

int main() {
    int w;
    int p = -1;
    int i, j;

    for (i=0; i<5; i++) {
        int temp, sum = 0;

        for (j=0; j<4; j++) {
            cin >> temp;
            sum += temp;
        }

        if (sum > p) {
            w = i+1;
            p = sum;
        }
    }

    cout << w << " " << p << endl;

    return 0;
}
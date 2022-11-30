#include<iostream>

using namespace std;

int main() {

    int a, b, r;
    int ra = 0, rb = 0;

    cin >> a >> b;

    while (a != 0) {
        r = a % 10;
        ra = ra * 10 + r;
        a /= 10;
    }

    while (b != 0) {
        r = b % 10;
        rb = rb * 10 + r;
        b /= 10;
    }

    if (ra >= rb) {
        cout << ra << endl;
    } else {
        cout << rb << endl;
    }

    return 0;
}
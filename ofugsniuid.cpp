#include<iostream>

using namespace std;

void out()
{
    int c;
    if (cin >> c) {
        out();
        cout << c << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    out();
    
    return 0;
}
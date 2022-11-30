#include<iostream>
#include<algorithm>

using namespace std;


int main() {
    
    int n, i;
    cin >> n;

    int arr[max(4, n+1)];
    
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    
    for (i=4; i<n+1; i++) {
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }
    
    cout << arr[n] << endl;
    
    return 0;
}
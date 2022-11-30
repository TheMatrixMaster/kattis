#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
    int n, i;
    int r, e, c;
    vector<string> vec;
    
    cin >> n;
    
    for (i=0; i<n; i++) {
        
        cin >> r >> e >> c;
        
        if (r == e-c) {
            vec.push_back("does not matter");
        } else if (r > e-c) {
            vec.push_back("do not advertise");
        } else {
            vec.push_back("advertise");
        }
    }
    
    for (string s : vec) {
        cout << s << endl;        
    }

    return 0;
}
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
    int n, i;
    string s, ns;
    vector<string> vec;
    
    
    cin >> n;
    
    while (n >= 0 && getline(cin, s)) {
        if (s.rfind("Simon says", 0) == 0) {
            vec.push_back(s.substr(10));
        }
        n -= 1;
    }

    for (string ss : vec) {
        cout << ss << endl;
    }
    
    
    return 0;
}
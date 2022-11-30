#include<iostream>
#include<string>

using namespace std;

int main() {
    int i;
    char c;
    string s, ns;
    
    cin >> s;
    
    for (i=0; i<s.length(); i++) {
        if (s[i] == c) continue;
        else {
            ns += s[i];
            c = s[i];
        }
    }

    cout << ns << endl;
    
    return 0;
}
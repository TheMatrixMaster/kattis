#include<bits/stdc++.h>

using namespace std;

unordered_map<int, int> m;
int overall = 0;

int main()
{  
    int N, Q;
    cin >> N >> Q;
    
    int i, x;
    string cmd;

    for (int j=0; j<Q; j++) {
        cin >> cmd;

        if (cmd == "RESTART") {
            cin >> overall;
            m.clear();
        } else if (cmd == "SET") {
            cin >> i >> x;
            m[i] = x;
        } else if (cmd == "PRINT") {
            cin >> i;
            if (m.find(i) != m.end()) {
                cout << m[i] << endl;
            } else {
                cout << overall << endl;
            }
        }
    }
    
    return 0;
}
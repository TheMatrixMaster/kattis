#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {

    int n, i;
    cin >> n;

    string s;
    vector<string> vec;

    while (n != -1) {
        int mph, nt;
        int lt = 0;
        int sum = 0;

        for (i=0; i<n; i++) {
            cin >> mph >> nt;

            sum += (mph * (nt - lt));
            lt = nt;
        }

        s = to_string(sum) + " miles";
        vec.push_back(s);

        cin >> n;
    }

    for (string s : vec) {
        cout << s << endl;
    }

    return 0;
}
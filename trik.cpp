#include<iostream>
#include<map>
#include<string>
#include<utility>

using namespace std;

int main() {

    map<pair<char, int>, int> m = {
        { make_pair('A', 1), 2 },
        { make_pair('A', 2), 1 },
        { make_pair('B', 2), 3 },
        { make_pair('B', 3), 2 },
        { make_pair('C', 1), 3 },
        { make_pair('C', 3), 1 }
    };

    pair<char, int> next;
    int b = 1;
    string s;

    cin >> s;

    for (char c : s) {
        next = make_pair(c, b);

        if (auto search = m.find(next);  search != m.end()) {
            b = search->second;
        }
    }

    cout << b << endl;

    return 0;
}
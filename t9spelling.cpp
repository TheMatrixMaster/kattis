#include<iostream>
#include<string>
#include<map>

using namespace std;

map<int, int> fl = {
    {97, 2},
    {100, 3},
    {103, 4},
    {106, 5},
    {109, 6},
    {112, 7},
    {116, 8},
    {119, 9},
};

int main()
{
    int n;
    string line;
    cin >> n;
    cin.get();

    for (int i=1; i<=n; i++) {

        if (!getline(cin, line)) break;

        string out = "";
        int num, rep, ord;
        int prev = -1;

        for (char c : line) {
            
            if (c == ' ') {
                num = 0;
                rep = 1;
            } else {
                ord = (int) c;
                auto itr = fl.lower_bound(ord);
                
                if (itr->first != ord) itr--;

                num = itr->second;
                rep = ord + 1 - itr->first;
            }
            
            if (prev == num) {
                out = out + " " + string(rep, '0' + num);
            } else {
                out += string(rep, '0' + num);
            }

            prev = num;
        }

        cout << "Case #" << i << ": " << out << endl;
    }

    return 0;
}
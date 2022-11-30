#include<iostream>
#include<unordered_set>

using namespace std;

unordered_set<unsigned long> jack;

int main()
{
    long n, m, i;
    long r = 0;
    unsigned long tmp;

    cin >> n >> m;

    while (n > 0 || m > 0) {

        for (i=0; i<n; i++) {
            cin >> tmp;
            jack.insert(tmp);
        }

        for (i=0; i<m; i++) {
            cin >> tmp;
            if (jack.count(tmp)) {
                r += 1;
            }
        }

        cout << r << endl;

        r = 0;
        jack.clear();
        cin >> n >> m;
    }

    return 0;
}
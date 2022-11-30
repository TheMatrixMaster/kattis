#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    
    int n, i, tmp;

    cin >> n;

    vector<int> vec;

    while (cin >> tmp) {
        if (tmp != 0) {
            vec.push_back(tmp);
        }
    }

    int best = 0;
    int acc = 0;
    int sum = 0;

    reverse(vec.begin(), vec.end());

    for (i=0; i<vec.size(); i++) {
        acc += vec[i];
        sum += (vec.size()-i)*vec[i];

        if (acc > best) {
            best = acc;
        }
    }

    cout << (sum+best) << endl;

    return 0;
}
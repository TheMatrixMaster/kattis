#include<iostream>
#include<vector>

using namespace std;

int main() {

    int p, i, right, index;
    vector<int> vec;

    cin >> p;

    for (i=0; i<p; i++) {
        cin >> right;

        if (vec.size() == 0 || right > vec.back()) {
            vec.push_back(right);
        } else {
            auto itr = lower_bound(vec.begin(), vec.end(), right) ;
            index = distance(vec.begin(), itr); 
            vec[index] = right;      
        }
    }

    cout << vec.size() << endl;

    return 0;
}
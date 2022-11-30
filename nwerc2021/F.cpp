#include <iostream>
#include <vector>
#include <complex>
using namespace std;

using ll = long long;
using ld = long double;
using lc = complex<ld>;

ll xs, ys, xe, ye;
ld eps = 1e-4;

ll count(vector<pair<ll, ll>> points, bool below) {
    vector<pair<ld, ld>> slopes;
    for (int i = 0; i < points; i++) {

    }

}

int main() {
    cin >> xs >> ys >> xe >> ye;
    ld m = (ld)(ye-ys)/(xe-xs);
    ld b = (ld)ys-m*xs;

    lc start = {xs, ys}, end = {xe, ye};
    lc slope = (end-start);

    int n; cin >> n;

    vector<lc> above, below, on;
    // subtract start and divide by slope to get everything between (0,0) and (1,0)
    for (int i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        lc point = {x, y};
        point -= start;
        point /= slope;
        if (abs(point.imag()) <= eps) on.push_back(point);

    }

    ll total = 0;
    // count the blocks on the line
    ll before = 0;
    for (auto [x, y] : on) {
        if (x < xs) before++;
    }
    total += (before)*(before-1)/2;
    total += (on.size()-before)*(on.size()-before-1)/2;

    total += count(above, false);
    total += count(below, true);

}
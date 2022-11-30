#include <iostream>
#include <queue>
#include <array>
#include <cassert>
using namespace std;

int other(int x, int a, int b) {
    if (x == a) return b;
    return a;
}

int main() {
    int n; cin >> n;
    priority_queue<array<int, 4> > known;
    vector<int> ans(n+1, -1);

    for (int i = 1; i <= n; i += 2) {
        cout << "? " << i << " " << i+1 << endl;
        int a, b; cin >> a >> b;
        known.push({min(a, b), max(a, b), i, i+1});
    }
    int qs = 0;

    while (known.size()) {
        auto top = known.top();
        known.pop();
        if (top[0] == top[1]) {
            ans[top[2]] = top[0];
            ans[top[3]] = top[1];
        }
        else {
            if (known.size() == 0) {
                auto [a, b, i, j] = top;
                for (int k = 1; k <= n+1; k++) {
                    if (ans[k] == a) {
                        // i,j,k has a,a,b
                        while (true) {
                            int x, y;
                            cout << "? " << i << " " << k << endl;
                            assert(qs < 92000);
                            qs++;
                            cin >> x >> y;
                            if (x == y) {
                                ans[i] = a;
                                ans[k] = a;
                                ans[j] = b;
                                break;
                            }
                            cout << "? " << i << " " << j << endl;
                            assert(qs < 92000);
                            qs++;
                            cin >> x >> y;
                            if (x == y) {
                                ans[i] = a;
                                ans[j] = a;
                                ans[k] = b;
                                break;
                            }
                        }
                        break;
                    }
                }
            }
            else {
                auto second = known.top();
                known.pop();
                auto prev = second;
                assert(qs < 92000);
                cout << "? " << top[2] << " " << second[2] << endl;
                qs++;
                int a, b; cin >> a >> b;
                if ((a != top[0] && a != top[1]) || (b != second[0] && b != second[1])) swap(a, b);
                if (a == b) {
                    ans[top[2]] = a;
                    ans[second[2]] = b;
                    ans[top[3]] = other(a, top[0], top[1]);
                    ans[second[3]] = other(b, second[0], second[1]);
                }
                else {
                    ans[top[3]] = other(a, top[0], top[1]);
                    ans[second[3]] = other(b, second[0], second[1]);
                    known.push({min(a, b), max(a,b), top[2], second[2]});
                    if (top[0] == second[0] && top[1] == second[1]) 
                        known.push({top[0], top[1], top[3], second[3]});
                }
            }
        }
    }

    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
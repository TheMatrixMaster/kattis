#include<iostream>
#include<utility>
#include<queue>
#include<map>
#include<vector>

using namespace std;

typedef pair<int, int> pii;

vector<int> indarr;
priority_queue<pii> q;
map<int, vector<int>> t;

int main() {

    int n, g, h;
    cin >> n;

    for (int i=1; i<=n; i++) {
        cin >> g;
        indarr.push_back(i);
        q.push(make_pair(g, i));
    }

    for (int i=1; i<=n; i++) {
        cin >> h;
        t[h].push_back(i);
    }

    while (!q.empty()) {
        pii p = q.top();

        int target = t[p.first].back();

        
    }

    return 0;
}

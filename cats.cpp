#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

auto comp = [](vi a, vi b) { return a[0] >= b[0]; };
priority_queue<vi, vvi, decltype(comp)> E(comp);
vi MST;

int parents[2005];
int ranks[2005];

int find(int i) {
    if (parents[i] != i) {
        parents[i] = find(parents[i]);
    }
    return parents[i];
}

void Union(int x, int y) {
    if (ranks[x] < ranks[y]) {
        parents[x] = y;
    } 
    else if (ranks[x] > ranks[y]) {
        parents[y] = x;
    } else {
        parents[y] = x;
        ranks[x] += 1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T, M, C;

    cin >> T;

    for (int i=0; i<T; i++) {
        MST.clear();
        while (!E.empty()) E.pop();
        memset(parents, 0, sizeof(parents));
        memset(ranks, 0, sizeof(ranks));

        cin >> M >> C;

        for (int j=0; j<C; j++) {
            parents[j] = j;
            ranks[j] = 0;
        }

        int u, v, d;
        for (int j=0; j<((C*(C-1))/2); j++) {
            cin >> u >> v >> d;
            vi edge = { d, u, v };
            E.push(edge);
        }

        while (MST.size() < C-1) {
            vi edge = E.top(); E.pop();

            int x = find(edge[1]);
            int y = find(edge[2]);

            if (x != y) {
                Union(x, y);
                MST.push_back(edge[0]);
            }
        }

        int sum = accumulate(MST.begin(), MST.end(), 
            decltype(MST)::value_type(0));

        if (M-sum >= C) {
            cout << "yes" << '\n';
        } else {
            cout << "no" << '\n';
        }
    }

    return 0;
}
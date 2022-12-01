#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

map<int, vii> E;

int parents[2505];
int ranks[2505];

vector<ii> MST;

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
    }
    else {
        parents[y] = x;
        ranks[x] += 1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, w;
    cin >> n;

    for (int i=1; i<=n; i++) {
        // setup union find
        parents[i] = i;
        ranks[i] = 0;

        // store edges sorted by weight in ordered map
        for (int j=1; j<=n; j++) {
            cin >> w;
            if (j > i) {
                E[w].push_back(make_pair(i, j));
            }
        }
    }

    for (auto& it : E) {
        for (ii edge : it.second) {
            int x = find(edge.first);
            int y = find(edge.second);
            
            if (x != y) {
                // this edge has two endpoints in disjoint sets 
                // so we can safely union them without creating a cycle

                Union(x, y);
                MST.push_back(edge);
            }
        }
    }

    // sort edges by first element of pair
    sort(MST.begin(), MST.end());

    for (ii edge : MST) {
        cout << edge.first << ' ' << edge.second << '\n';
    }

    return 0;
}
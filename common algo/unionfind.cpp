#include <bits/stdc++.h>

using namespace std;

#define MAX 1000005

int parents[MAX];
int ranks[MAX];

int find(int i) {
    if (parents[i] != i) {
        // path compression
        parents[i] = find(parents[i]);
    }

    return parents[i];
}

void Union(int x, int y) {
    // union by rank
    if (x == y) return;
    if (ranks[x] > ranks[y]) {
        parents[y] = x;
    } else if (ranks[x] < ranks[y]) {
        parents[x] = y;
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

    int N, Q;

    cin >> N >> Q;

    for (int i=1; i<=N; i++) {
        parents[i] = i;
        ranks[i] = 0;
    }

    char op;
    int x, y;

    for (int j=0; j<Q; j++) {
        cin >> op >> x >> y;

        if (op == '=') {
            Union(find(x), find(y));
        } else if (op == '?') {
            if (find(x) == find(y)) cout << "yes" << '\n';
            else cout << "no" << '\n';
        }
    }

    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int parents[300005];
int ranks[300005];
int capacities[300005];

int find(int i) {
    if (parents[i] != i) {
        parents[i] = find(parents[i]);
    }

    return parents[i];
}

int Union(int x, int y) {
    if (x == y) {
        // check if drawer can accomodate an extra item
        return x;
    }

    if (ranks[x] < ranks[y]) {
        parents[x] = y;
        capacities[y] += capacities[x];
        return y;
    }
    else if (ranks[x] > ranks[y]) {
        parents[y] = x;
        capacities[x] += capacities[y];
        return x;
    }
    else {
        parents[y] = x;
        ranks[x] += 1;
        capacities[x] += capacities[y];
        return x;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L;

    cin >> N >> L;

    for (int i=1; i<=L; i++) {
        parents[i] = i;
        ranks[i] = 0;
        capacities[i] = 1;
    }

    int a, b;

    for (int j=1; j<=N; j++) {
        cin >> a >> b;

        int flag = Union(find(a), find(b));

        if (capacities[flag] > 0) {
            cout << "LADICA" << '\n';
            capacities[flag]--;
        } else {
            cout << "SMECE" << '\n';
        }
    }

    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int parents[200005];
int ranks[200005];
int sizes[200005];
unordered_map<string, int> names;

int find(int i) {
    if (parents[i] != i) {
        parents[i] = find(parents[i]);
    }
    return parents[i];
}

int union_get_size(int x, int y) {
    if (x == y) return sizes[x];

    if (ranks[x] < ranks[y]) {
        parents[x] = y;
        sizes[y] += sizes[x];
        return sizes[y];
    } else if (ranks[x] > ranks[y]) {
        parents[y] = x;
        sizes[x] += sizes[y];
        return sizes[x];
    } else {
        parents[y] = x;
        sizes[x] += sizes[y];
        return sizes[x];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, F;
    cin >> N;

    for (int i=0; i<N; i++) {

        fill(parents, end(parents), 0);
        fill(ranks, end(ranks), 0);
        fill(sizes, end(sizes), 0);
        names.clear();

        int name_counter = 0;
        string line, first, second;
        cin >> F;
        cin.get();

        for (int j=0; j<F; j++) {
            getline(cin, line);
            istringstream iss(line);

            iss >> first >> second;

            if (names.find(first) == names.end()) {
                names[first] = name_counter;
                parents[name_counter] = name_counter;
                ranks[name_counter] = 0;
                sizes[name_counter] = 1;
                name_counter++;
            }

            if (names.find(second) == names.end()) {
                names[second] = name_counter;
                parents[name_counter] = name_counter;
                ranks[name_counter] = 0;
                sizes[name_counter] = 1;
                name_counter++;
            }



            int x = find(names[first]);
            int y = find(names[second]);

            cout << union_get_size(x, y) << '\n';
        }

    }

    return 0;
}
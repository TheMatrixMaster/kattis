#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<set>

using namespace std;

set<pair<int, int>> bag;
int map[1005][1005];

void bfs(pair<int, int> s, int target, int counter) {
    if (map[s.first][s.second] != target) return;
    else {
        map[s.first][s.second] = counter;
        bfs(make_pair(s.first+1, s.second), target, counter);
        bfs(make_pair(s.first-1, s.second), target, counter);
        bfs(make_pair(s.first, s.second+1), target, counter);
        bfs(make_pair(s.first, s.second-1), target, counter);
        bag.erase(s);
    }
}

int main()
{
    string line;
    int r, c, tmp;
    cin >> r >> c;

    cin.get();
    memset(map, -1, sizeof(map));

    for (int i=1; i<=r; i++) {
        getline(cin, line);
        for (int j=1; j<=c; j++) {
            map[i][j] = line[j-1] - '0';
            bag.insert(make_pair(i, j));
        }
    }

    int target;
    int counter = 2;
    pair<int, int> p;

    while (!bag.empty()) {
        p = *bag.begin();
        target = map[p.first][p.second];
        bfs(p, target, counter*10+target);
        counter += 1;
    }

    // for (int i=1; i<=r; i++) {
    //     for (int j=1; j<=c; j++) {
    //         cout << map[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int n, r1, c1, r2, c2;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> r1 >> c1 >> r2 >> c2;
        if (map[r1][c1] == map[r2][c2]) {
            if (map[r1][c1] % 10 == 0) {
                cout << "binary" << endl;
            } else {
                cout << "decimal" << endl;
            }
        } else {
            cout << "neither" << endl;
        }
    }

    return 0;
}
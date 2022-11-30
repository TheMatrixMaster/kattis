#include<iostream>
#include<cstring>
#include<set>

using namespace std;

set<pair<int, int>> bag;
char canvas[105][105];

void bfs(pair<int, int> s) {
    if (canvas[s.first][s.second] != '-') return;
    else {
        canvas[s.first][s.second] = '#';
        bfs(make_pair(s.first+1, s.second));
        bfs(make_pair(s.first-1, s.second));
        bfs(make_pair(s.first, s.second+1));
        bfs(make_pair(s.first, s.second-1));
        bag.erase(s);
    }
}

int main()
{
    int count = 1;
    int m, n;
    char c;

    while (cin >> m >> n) {
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                cin >> c;
                if (c == '-') bag.insert(make_pair(i, j));
                canvas[i][j] = c;
            }
        }

        int r = 0;
        pair<int, int> p;

        while (!bag.empty()) {
            p = *bag.begin();
            bfs(p);
            r += 1;
        }

        cout << "Case " << count << ": " << r << endl;

        count += 1;
        bag.clear();
        memset(canvas, 0, sizeof(canvas));
    }

    return 0;
}
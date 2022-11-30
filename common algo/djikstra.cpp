#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<cstring>
#include<utility>
#include<limits>

using namespace std;

typedef pair<int, int> pii;

int dist[10005];
map<int, vector<pii>> edges;
auto comp = [](pii a, pii b) { return a.second >= b.second; };
priority_queue<pii, vector<pii>, decltype(comp)> pq(comp);

void djikstra(int s) {
    int i;
    pii v, u;

    while (!pq.empty()) {
        u = pq.top(); pq.pop();

        for (i=0; i<edges[u.first].size(); i++) {
            v = edges[u.first][i];
            if (u.second + v.second < dist[v.first]) {
                dist[v.first] = u.second + v.second;
                v.second = dist[v.first];
                pq.push(v);
            }
        }
    }
}

int main() {
    int n, m, q, s;
    int u, v, w;
    int i, j;
    pii p;

    cin >> n >> m >> q >> s;

    while ((n | m | q | s) != 0) {
        // reset priority queue and visited nodes
        edges.clear();
        memset(dist, 0, sizeof(dist));
        while (!pq.empty()) pq.pop();

        // initialize priority queue and distance matrix
        // we set source distance to 0 and all other distances to +infinity
        for (i=0; i<n; i++) dist[i] = (numeric_limits<int>::max());
        dist[s] = 0; pq.push(make_pair(s, 0));

        // collect edges and weights into two matrices
        for (i=0; i<m; i++) {
            cin >> u >> v >> w;
            edges[u].push_back(make_pair(v, w));
        }

        // run djikstra's algorithm
        djikstra(s);

        // for each of the queries, we return the final computed distance if it exists
        for (i=0; i<q; i++) {
            cin >> j;
            if (dist[j] < numeric_limits<int>::max()) {
                cout << dist[j] << endl;
            } else {
                cout << "Impossible" << endl;
            }
        }

        cout << '\n';
        cin >> n >> m >> q >> s;
    }

    return 0;
}

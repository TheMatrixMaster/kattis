#include<iostream>
#include<queue>
#include<map>
#include<cstring>
#include<limits.h>

using namespace std;

typedef pair<int, int> pii;

int dist[155][155];
int visited[155];
map<int, vector<pii>> edges;

auto comp = [](pii a, pii b) { return a.second >= b.second; };
priority_queue<pii, vector<pii>, decltype(comp)> pq(comp);

void djikstra(int s) {    
    while (!pq.empty()) {
        pii u = pq.top();
        pq.pop();

        if (visited[u.first]) continue;

        for (pii v : edges[u.first]) {
            if (!visited[v.first]) {
                if (u.second + v.second < dist[s][v.first]) {
                    dist[s][v.first] = u.second + v.second;
                    v.second = dist[s][v.first];
                    pq.push(v);
                }
            }
        }

        visited[u.first] = 1;
    }
}

int main()
{
    int n, m, q;

    cin >> n >> m >> q;

    while ((n | m | q) != 0) {
        memset(visited, 0, sizeof(visited));
        edges.clear();
        while (!pq.empty()) pq.pop();

        for (int i=0; i<n; i++) {
            dist[i][i] = 0;
            memset(dist[i], numeric_limits<int>::max(), sizeof(dist[i]));
        }

        int u, v, w;

        for (int j=0; j<m; j++) {
            cin >> u >> v >> w;
            edges[u].push_back(make_pair(v, w));
        }

        for (int s=0; s<n; s++) {
            memset(visited, 0, sizeof(visited));
            pq.push(make_pair(s, 0));
            djikstra(s);
        }

        cout << endl;

        for (int j=0; j<q; j++) {
            cin >> u >> v;

            if (dist[u][v] == numeric_limits<int>::max()) {
                cout << "Impossible" << endl;
            } else {
                cout << dist[u][v] << endl;
            }
        }

        cin >> n >> m >> q;
    }

    return 0;
}
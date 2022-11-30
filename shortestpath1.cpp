#include<iostream>
#include<algorithm>
#include<vector>
#include<limits>
#include<utility>
#include<map>

using namespace std;

vector<int> dist;
vector<pair<int, int>> pq;
map<int, vector<pair<int, int>>> edges;

auto comp = [](pair<int, int> a, pair<int, int> b) { return a.second >= b.second; };

void djikstra(int s) {
    int i;
    pair<int, int> v;
    pair<int, int> u;

    while (!pq.empty()) {
        u = pq.front();

        pop_heap(pq.begin(), pq.end(), comp); 
        pq.pop_back();

        for (i=0; i<edges[u.first].size(); i++) {
            v = edges[u.first][i];
            if (u.second + v.second < dist[v.first]) {
                dist[v.first] = u.second + v.second;
                v.second = dist[v.first];
                pq.push_back(v); 
                push_heap(pq.begin(), pq.end(), comp);
            }
        }
    }
}

int main() {
    int n, m, q, s;
    int u, v, w;
    int i, j;
    pair<int, int> p;

    cin >> n >> m >> q >> s;

    while ((n | m | q | s) != 0) {
        // reset priority queue and visited nodes
        pq.clear();
        dist.clear();
        edges.clear();

        // initialize priority queue and distance matrix
        // we set source distance to 0 and all other distances to +infinity
        for (i=0; i<n; i++) {
            dist.push_back(numeric_limits<int>::max());
        }
        dist[0] = 0;
        pq.push_back(make_pair(0, 0));

        make_heap(pq.begin(), pq.end(), comp);

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

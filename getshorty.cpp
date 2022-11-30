#include<iostream>
#include<algorithm>
#include<vector>
#include<limits>
#include<utility>
#include<map>
#include <iomanip>

using namespace std;

vector<float> dist;
vector<pair<int, float>> pq;
map<int, vector<pair<int, float>>> edges;

auto comp = [](pair<int, float> a, pair<int, float> b) { return a.second <= b.second; };

void djikstra(int s) {
    int i;
    pair<int, float> v;
    pair<int, float> u;

    while (!pq.empty()) {
        u = pq.front();

        pop_heap(pq.begin(), pq.end(), comp); 
        pq.pop_back();

        for (i=0; i<edges[u.first].size(); i++) {
            v = edges[u.first][i];
            if (u.second * v.second > dist[v.first]) {
                dist[v.first] = u.second * v.second;
                v.second = dist[v.first];
                pq.push_back(v);
                push_heap(pq.begin(), pq.end(), comp);
            }
        }
    }
}

int main() {
    int n, m, i;
    int u, v;
    float w;

    cin >> n >> m;
    cout << fixed << setprecision(4);

    while ((n | m) != 0) {
        // reset priority queue and visited nodes
        pq.clear();
        dist.clear();
        edges.clear();

        // initialize priority queue and distance matrix
        // we set source distance to 0 and all other distances to -infinity
        for (i=0; i<n; i++) {
            dist.push_back(numeric_limits<float>::min());
        }
        dist[0] = 1.0;
        pq.push_back(make_pair(0, 1.0));

        make_heap(pq.begin(), pq.end(), comp);

        // collect edges and weights into matrix
        for (i=0; i<m; i++) {
            cin >> u >> v >> w;
            edges[u].push_back(make_pair(v, w));
            edges[v].push_back(make_pair(u, w));
        }

        // run djikstra's algorithm
        djikstra(0);

        // output the minimal factored distance from node 0 to n-1
        cout << dist[n-1] << endl;

        cin >> n >> m;
    }

    return 0;
}

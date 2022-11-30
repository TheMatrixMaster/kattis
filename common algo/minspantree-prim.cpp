#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<cstring>
#include<utility>
#include<limits>

using namespace std;

typedef pair<int, int> Node;

int weights[20000];
int parents[20000];
bool visited[20000];
map<int, vector<Node>> edges;
vector<Node> MST;

// we want nodes with smallest weight to come out of the PQ first
auto comp = [](Node a, Node b) { return a.second >= b.second; };
priority_queue<Node, vector<Node>, decltype(comp)> pq(comp);

int prim_djikstra()
{
    Node u;
    long long cost = 0;

    while (!pq.empty()) {
        u = pq.top(); pq.pop();

        if (visited[u.first]) continue;

        visited[u.first] = true;

        if (weights[u.first] == numeric_limits<int>::max()) { 
            cost = -1; break; 
        } else { 
            cost += weights[u.first];
            if (parents[u.first] != -1) {
                MST.push_back(make_pair(
                    min(u.first, parents[u.first]),
                    max(u.first, parents[u.first])
                ));
            }
        }

        for (Node v : edges[u.first]) {
            if (!visited[v.first]) {
                if (v.second < weights[v.first]) {
                    weights[v.first] = v.second;
                    parents[v.first] = u.first;
                    pq.push(v);
                }
            }
        }
    }

    return cost;
}

int main()
{
    int n, m;
    int u, v, w;

    cin >> n >> m;

    while (n || m) {

        MST.clear();
        edges.clear();
        while (!pq.empty()) pq.pop();
        memset(parents, -1, sizeof(weights));
        memset(weights, 0, sizeof(weights));
        memset(visited, false, sizeof(visited));
        
        pq.push(make_pair(0, 0));
        for (int i=1; i<n; i++) {
            visited[i] = false;
            weights[i] = numeric_limits<int>::max();
            pq.push(make_pair(i, weights[i]));
        }

        for (int j=0; j<m; j++) {
            cin >> u >> v >> w;
            edges[u].push_back(make_pair(v, w));
            edges[v].push_back(make_pair(u, w));
        }

        int cost = prim_djikstra();

        if (cost == -1 || MST.size() != n-1) {
            cout << "Impossible" << endl;
        } else {
            cout << cost << endl;
            sort(MST.begin(), MST.end());

            for (int i=0; i<n-1; i++) {
                cout << MST[i].first << " " << MST[i].second << endl;
            }
        }

        cin >> n >> m;
    }

    return 0;
}
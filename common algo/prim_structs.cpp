#include<iostream>
#include<algorithm>
#include<queue>
#include<limits>
#include<string>
#include<cstring>

using namespace std;

typedef struct Node {
    int id;
    int visited;
    int weight;
    Node* parent;
    vector<Node*> adj_list;
} Node;

// we want nodes with smallest weight to come out of the PQ first
auto comp = [](Node* a, Node* b) { return a->weight >= b->weight; };
priority_queue<Node*, vector<Node*>, decltype(comp)> Q(comp);

Node nodes[20000];
vector<int> MST[20000];
int weights[20000][20000];

int prim_djikstra()
{
    Node* cur;
    int cost = 0;

    // for (cout << 'Q' << ": \t"; !Q.empty(); Q.pop())
    //     cout << Q.top()->weight << ' ';
    // cout << '\n';
    // return;
    
    while (!Q.empty()) {
        cur = Q.top(); Q.pop();
        cur->visited = true;

        if (cur->weight == numeric_limits<int>::max()) {
            // cout << "Impossible: " << cur->id << endl;
            cost = -1;
            break;
        } else {
            cost += cur->weight;
            if (cur->parent) MST[cur->parent->id].push_back(cur->id);
            // cout << "Possible: " << cur->id << ": " << cur->weight << endl;
        }

        for (Node* n : cur->adj_list) {
            if (!n->visited) {
                if (weights[cur->id][n->id] < n->weight) {
                    n->weight = weights[cur->id][n->id];
                    n->parent = cur;
                }
            }
        }
    }

    return cost;
}

int main()
{
    int i, j;
    int n, m;
    int u, v, w;
    cin >> n >> m;

    while (n || m) {

        for (i=0; i<n; i++) {
            nodes[i].id = i;
            nodes[i].visited = false;
            nodes[i].weight = numeric_limits<int>::max();
            nodes[i].parent = NULL;
        }

        nodes[0].weight = 0;

        for (j=0; j<m; j++) {
            cin >> u >> v >> w;
            weights[u][v] = weights[v][u] = w;
            nodes[u].adj_list.push_back(&nodes[v]);
            nodes[v].adj_list.push_back(&nodes[u]);
        }

        for (int i=0; i<n; i++) Q.push(&nodes[i]);
        int cost = prim_djikstra();

        if (cost == -1) cout << "Impossible" << endl;
        else {
            cout << cost << endl;
            for (i=0; i<n; i++) {
                while (!MST[i].empty()) {
                    cout << i << " " << MST[i].back() << endl;
                    MST[i].pop_back();
                }
            }
        }

        for (auto v : MST) v.clear();
        while (!Q.empty()) Q.pop();

        memset(nodes, 0, sizeof(nodes));
        memset(weights, 0, sizeof(weights));
        cin >> n >> m;
    }

    return 0;
}
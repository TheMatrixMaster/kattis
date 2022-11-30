#include<iostream>
#include<vector>

using namespace std;

int houses[200001];
vector<int> cables[200001];

void bfs(int s)
{
    if (houses[s] != 1) return;
    for (int c : cables[s]) {
        houses[s] = 0;
        bfs(c);
    }
}

int main()
{
    int n, m;
    int a, b;
    cin >> n >> m;
    
    for (int i=1; i<=n; i++) houses[i] = 1;
    for (int j=0; j<m; j++) {
        cin >> a >> b;
        cables[a].push_back(b);
        cables[b].push_back(a);
    }
    
    bfs(1);
    
    bool connected = true;
    for (int i=2; i<=n; i++) {
        if (houses[i] == 1) {
            cout << i << endl;
            connected = false;
        }
    }
    
    if (connected) cout << "Connected" << endl;
    
    return 0;
}
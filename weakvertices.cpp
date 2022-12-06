#include<bits/stdc++.h>

using namespace std;

int isweak[20];
int adj_matrix[20][20];
vector<pair<int, int>> E;

int main()
{
    int n, t;
    
    while (cin >> n && n != -1) {
        E.clear();
        memset(adj_matrix, 0, sizeof(adj_matrix));

        for (int i=0; i<n; i++) {
            isweak[i] = 1;
            for (int j=0; j<n; j++) {
                cin >> t;
                if (t == 1) {
                    adj_matrix[i][j] = 1;
                    if (j > i) E.push_back(make_pair(i, j));
                }
            }
        }
        
        for (pair<int, int> edge : E) {
            for (int i=0; i<n; i++) {
                if (
                    adj_matrix[i][edge.first] == 1 &&
                    adj_matrix[i][edge.second] == 1
                ) {
                    // cout << edge.first << ',' << edge.second << ',' << i << '\n';

                    isweak[edge.first] = 
                    isweak[edge.second] = 0;
                }
            }
        }

        for (int i=0; i<n; i++) {
            if (isweak[i] == 1) {
                cout << i << ' ';
            }
        }
        cout << '\n';
    }
    
    return 0;
}


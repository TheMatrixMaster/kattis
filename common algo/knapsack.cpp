#include<iostream>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;

constexpr int MAX_CAPACITY = 2001;
constexpr int MAX_OBJECTS = 2001;

int P[MAX_CAPACITY][MAX_OBJECTS];
int S[MAX_CAPACITY][MAX_OBJECTS];
vector<pair<int, int>> OBJECTS;
vector<int> RESULT;

void collect_items(int K, int N)
{
    int k=K;
    int n=N;

    for (; n>=0; n--) {
        if (P[k][n] != 0) {
            // cout << k << "," << n << ": " << P[k][n] << endl;
            RESULT.push_back(n-1);
            k -= OBJECTS[n-1].first;
        }
    }
}

void knapsack(int K, int N)
{
    /*  initialize base case values for P
        P[0, N] = 0
        P[K, 0] = 0
        P[0, 0] = 0
    */
    int i;
    for (i=0; i<MAX_CAPACITY; i++) {
        P[0][i] = 0;
        P[i][0] = 0;
    }

    /*  run dynamic programming knapsack solution
        if (w[N] < K) P[K, N] = max(P[K-w[N], N-1] + v[N], P[K, N-1])
        else if (w[N] == K) P[K, N] = max(v[N], P[K, N-1])
        else if (w[N] > K) P[K, N] = P[K, N-1]
    */
    int k, n, weight, value;
    for (n=1; n<=N; n++) {
        for (k=1; k<=K; k++) {
            weight = OBJECTS[n-1].first;
            value = OBJECTS[n-1].second;
            if (k == weight) {
                P[k][n] = max(value, P[k][n-1]);
                S[k][n] = value >= P[k][n-1] ? 1 : 0;
            }
            else if (k < weight) {
                P[k][n] = P[k][n-1];
                S[k][n] = 0;
            }
            else {
                P[k][n] = max(P[k-weight][n-1] + value, P[k][n-1]);
                S[k][n] = P[k-weight][n-1] + value >= P[k][n-1] ? 1 : 0;
            }
        }
    }
}

int main()
{
    int c, n;
    int v, w;

    while (cin >> c >> n) {
        for (int i=0; i<n; i++) {
            cin >> v >> w;
            OBJECTS.push_back(make_pair(w, v));
        }

        knapsack(c, n);
        collect_items(c, n);

        cout << RESULT.size() << endl;
        for (int s : RESULT) cout << s << ' ';
        cout << '\n';

        // re-initialize knapsack values
        memset(P, 0, MAX_CAPACITY*MAX_OBJECTS*sizeof(int));
        memset(S, 0, MAX_CAPACITY*MAX_OBJECTS*sizeof(int));
        OBJECTS.clear();
        RESULT.clear();
    }

    return 0;
}
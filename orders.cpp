#include<bits/stdc++.h>

using namespace std;

#define MAX_SUM 30005
#define MAX_ITEMS 105

int P[MAX_ITEMS][MAX_SUM];
int S[MAX_ITEMS][MAX_SUM];
int items[MAX_ITEMS];
vector<int> queries;

void collect_items(int K, int N) {
    if (P[N][K] == 0) {
        cout << "Impossible" << '\n';
    } else if (P[N][K] > 1) {
        cout << "Ambiguous" << '\n';
    } else if (P[N][K] == 1) {
        int n = N;
        int k = K;
        string res = "";

        for (; n>0; n--) {
            if (P[n][k] != 1) {
                cout << "Ambiguous" << '\n';
                res = "";
                break;
            }
            
            if (S[n][k] != 0) {
                /**
                 * tell result how many times we used item n and
                 * decrement target sum by that amount times cost of n 
                */
                for (int i=0; i<S[n][k]; i++)
                    res = to_string(n) + " " + res;

                k -= (S[n][k] * items[n]);
            }
        }

        if (res != "") cout << res << '\n';
    }
}

void knapsack(int K, int N) {
    /** @brief DP base case
     * Cannot fill up knapsack with no items P[0][k] = 0
     * Can always fill up knapsack of size 0 P[n][0] = 1
    */
    for (int i=0; i<=K; i++) P[0][i] = 0;
    for (int i=0; i<=N; i++) P[i][0] = 1;

    for (int n=1; n<=N; n++) {
        for (int k=1; k<=K; k++) {
            int cost = items[n];

            /*
             * If the current item can fill the knapsack alone, then we 
             * add this elements to the solution such that P[n][k] = cost.
             * We also add P[n-1][k] to P[n][k] since we want to know how many
             * different solutions we can obtain for P[n][k]. This is equal to 
             * the number of solutions without using item n: P[n-1][k] plus the
             * number of solutions that use n: P[n][k] = 1
            */
            if (cost == k) {
                P[n][k] = P[n-1][k] + 1;
                S[n][k] = 1;
            }
            /**
             * Current item is larger than target size, so we cannot use it.
             * Thus, P[n][k] = P[n-1][k]
            */
            else if (cost > k) {
                P[n][k] = P[n-1][k];
                S[n][k] = 0;
            }
            /**
             * Current item is smaller than target size so we can either
             * include it in the solution or not include it. We can use the 
             * same item many times, so we need to consider the sum of all
             * possible ways we can get to target size of K using any number
             * of copies of the item. Thus, 
             * 
             * P[n][k] = sum(P[n-1][k], P[n-1][k-v], P[n-1][k-2v], ...)
             * where v is the cost of the nth item.
            */
            else if (cost < k) {
                int t;
                for (int i=0; i * cost <= k; i++) {
                    t = P[n-1][k - (i * cost)];
                    if (t > 0) {
                        P[n][k] += t;
                        S[n][k] = i;
                    }
                }
            } 
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    for (int i=1; i<=n; i++) {
        cin >> items[i];
    }

    int m, k;
    int k_max = 0;
    cin >> m;

    for (int i=0; i<m; i++) {
        cin >> k;
        if (k > k_max) k_max = k;
        queries.push_back(k);
    }

    knapsack(k_max, n);

    for (int query : queries) {
        collect_items(query, n);
    }

    return 0;
}

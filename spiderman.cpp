#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
#include<vector>
#include<string>

using namespace std;

/** @brief DP on range of distances and target sum
 * 
 * Our goal is to minimize the height needed to travel 
 * a given range of distances (a1, a2, a3, ..., an) such that 
 * the target sum of these distances equals 0.
 * 
 * We use dynamic programming on both the range of distances 
 * AND the target sum such that P[N, K] represents the minimal
 * achievable height when attempting to travel the first N distances 
 * and arrive to a final height of K.
 *  
 * S[N, K] will hold the move executed by element N, when travelling
 * to the final height of K. This move is either UP (add N) or DOWN 
 * subtract (N).
 * 
 * The vector D is used to hold the distances provided as input
 * 
*/
int P[45][1005];
char S[45][1005];
vector<int> D;

int main()
{
    int c;
    cin >> c;

    for (int i=0; i<c; i++) {
        /**
         * We fill P[N, K] with INT_MAX since our default
         * assumption is that it is impossible to travel
         * to height K using the first N elements.
        */
        fill(P[0], P[0]+45*1005, INT_MAX);
        memset(S, 0, sizeof(S));
        D.clear();

        int N, v;
        int K = 0;
        cin >> N;

        /**
         * Collect all N input distances from stdin
         * and compute the maximal height that these 
         * distances can travel to.
        */
        for (int j=0; j<N; j++) {
            cin >> v;
            K += v;
            D.push_back(v);
        }

        /**
         * The minimal height required to travel
         * to height 0 using 0 elements is simply 0
        */
        P[0][0] = 0;

        for (int n=0; n<N; n++) {
            for (int k=0; k<=K; k++) {
                
                /** @brief DP logic
                 * 
                 * If I can travel to height k using the first n elements,
                 * then I can travel to height k+v and height k-v using the
                 * first n+1 elements where v is the (n+1)th element. However,
                 * I would only want to update P[n+1][k+v] and P[n+1][k-v] iff
                 * the minimal height used to travel to this target k, is smaller
                 * than the previous value of P[n+1][k±k]. 
                */

                if (P[n][k] != INT_MAX) {
                    v = D[n];

                    if (P[n+1][k+v] > max(P[n][k], k+v)) {
                        P[n+1][k+v] = max(P[n][k], k+v);
                        S[n+1][k+v] = 'U';
                    }

                    if (k-v >= 0 && P[n+1][k-v] > P[n][k]) {
                        P[n+1][k-v] = P[n][k];
                        S[n+1][k-v] = 'D';
                    }
                }
            }
        }

        /** @brief Reconstructing the moves
         * 
         * To output the solution, we need to traverse S in the 
         * reverse direction and find the moves that we made 
         * in order to achieve the minimal height P[N][0] when 
         * using all N elements to travel back to the starting point.
         * 
         * If we made an UP move at P[N][K], then we must examine 
         * the move made at P[N-1][K-v] where v is the nth distance.
         * 
         * Similarly, if we made a DOWN move at P[N][K], then we must
         * examine the move made at P[N-1][K+v]
        */

        if (P[N][0] == INT_MAX) cout << "IMPOSSIBLE" << endl;
        else {
            string out = "";
            int target = 0;
            for (int n=N; n>0; n--) {
                if (S[n][target] == 'D') {
                    target += D[n-1];
                    out = 'D' + out;
                } else if (S[n][target] == 'U') {
                    target -= D[n-1];
                    out = 'U' + out;
                }
            }
            cout << out << endl;
        }

    }

    return 0;
}

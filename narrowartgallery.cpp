#include<iostream>
#include<algorithm>
#include<limits>

using namespace std;

/*
 * DP table will store the minimal amount of value that
 * we can remove from the public for each combination of 
 * row count N, rooms to close K, and block shape 
 * (left protruding, right protruding, or flat)
*/
int DP[205][205][3];

int main()
{
    int N, K, r, k;
    int total_value = 0;

    cin >> N >> K;

    for (r=1; r<=N; r++) {
        int v1, v2;
        cin >> v1 >> v2;

        for (k=1; k<=K; k++) {
            /**
             * If r < k, this means that we are trying to block off more 
             * than one room per row which is impossible, so we set the DP
             * value to positive infinity.
             * 
             * If r == k, then we must either block off all rooms in the left 
             * column or all rooms in the right column. Thus, the minimum configuration
             * is simply the minimum between these two choices.
             * 
             * In the general case r > k, we first consider two options each
             * for the left and right protruding block shapes at row r:
             * 
             *  1) We close the protruding room (left or right) and sum its 
             *     value with the minimum value we had computed for closing k-1
             *     rooms in r-1 rows with the same protrusion shape
             *  2) We do not close the protruding room, and simply look for the 
             *     minimum value we had computed for closing k rooms in r-1 rows
             * 
             * Then, for the flat block shape at r rows, we simply take the minimum 
             * value between the left protruding and right protruding block shapes
             * that we have just computed above.
            */
            if (r < k) {
                DP[r][k][0] = numeric_limits<int>::max();
                DP[r][k][1] = numeric_limits<int>::max();
                DP[r][k][2] = numeric_limits<int>::max();
            }
            else if (r == k) {
                DP[r][k][0] = DP[r-1][k-1][0] + v1;
                DP[r][k][1] = DP[r-1][k-1][1] + v2;
                DP[r][k][2] = min(DP[r][k][0], DP[r][k][1]);
            }
            else {
                DP[r][k][0] = min(v1+DP[r-1][k-1][0], DP[r-1][k][2]);
                DP[r][k][1] = min(v2+DP[r-1][k-1][1], DP[r-1][k][2]);
                DP[r][k][2] = min(DP[r][k][0], DP[r][k][1]);
            }
        }

        total_value += (v1 + v2);
    }

    cin.clear();
    cin.ignore(numeric_limits<int>::max());

    /**
     * The output is simply the total value of all rooms
     * minus the minimal amount of value when removing K
     * rooms from N rows.
    */
    cout << total_value - DP[N][K][2] << endl;
}
#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>

using namespace std;

int main() {
    int n, m, p;
    int i, j;

    cin >> n;

    float out[n];

    cout << fixed << setprecision(3);

    for (i=0; i<n; i++) {
        cin >> m;
        
        int sum = 0;
        int passing = 0;
        int grades[m];

        for (j=0; j<m; j++) {
            cin >> p;
            grades[j] = p;
            sum += p;
        }

        float avg = sum / m;

        for (j=0; j<m; j++) {
            if (grades[j] > avg) {
                passing += 1;
            }
        }

        float res = (float)passing / (float)m * 100;
        out[i] = res;
    }

    for (i=0; i<n; i++) {
        cout << out[i] << '%' << endl;
    }
}

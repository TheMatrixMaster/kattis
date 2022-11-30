#include<iostream>

using namespace std;

int main() {
    int n, b, h, w;
    cin >> n >> b >> h >> w;
    
    int i, j, p, beds, tmp;
    int cost = b+1;
    
    for (i=0; i<h; i++) {
        cin >> p;
        
        for (j=0; j<w; j++) {
            cin >> beds;
            if (beds >= n && n*p < cost) {
                cost = n*p;
            }
        }
    }
    
    if (cost <= b) cout << cost << endl;
    else cout << "stay home" << endl;
    
    return 0;
}
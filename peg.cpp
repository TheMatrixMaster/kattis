#include<iostream> 
#include<vector>
#include<utility>

using namespace std;

int main() {
    int i, j;
    int count = 0;
    string line;
    char board[7][7] = { '\0' };
    vector<pair<int, int>> coords;
    
    while (cin >> line) {
        for (i=0; i<line.length(); i++) {

            if (line[i] == '.') {
                coords.push_back(make_pair(count, i));
            }

            if (2 <= count and count <= 4) {
                board[count][i] = line[i];
            } else {
                board[count][i+2] = line[i];
            }
        }
        count += 1;
    }

    int r = 0;

    for (pair<int, int> c : coords) {
        int x = c.first;
        int y = c.second;

        if (x+2 < 7 and board[x+2][y] == 'o' and board[x+1][y] == 'o') r += 1;
        if (x-2 >= 0 and board[x-2][y] == 'o' and board[x-1][y] == 'o') r += 1;
        if (y+2 < 7 and board[x][y+2] == 'o' and board[x][y+1] == 'o') r += 1; 
        if (y-2 >= 0 and board[x][y-2] == 'o' and board[x][y-1] == 'o') r += 1;
    }
    
    cout << r << endl;
    
    return 0;
}
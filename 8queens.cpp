#include <iostream>
#include <utility>
#include<unordered_set>
#include<set>

using namespace std;

set<pair<int, int>> invalid_pos;
unordered_set<int> invalid_rows, invalid_cols;

int main()
{
    pair<int, int> pos;
    int row, col;
    char curr;
    bool valid = true;
    int count = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> curr;
            if (curr == '*')
            {
                row = i;
                col = j;
                pos = make_pair(row, col);

                if (invalid_rows.count(row)) valid = false;
                else if (invalid_cols.count(col)) valid = false;
                else if (invalid_pos.count(pos)) valid = false;

                invalid_rows.insert(row);
                invalid_cols.insert(col);

                // cout << row << ' ' << col << endl;

                int diff = 1;
                for (int k = i + 1; k < 8; k++)
                {
                    if (j - diff >= 0) {
                        invalid_pos.insert(make_pair(k, j - diff));
                        // cout << k << ", " << j-diff << endl;
                    }
                    if (j + diff < 8) {
                        invalid_pos.insert(make_pair(k, j + diff));
                        // cout << k << ", " << j+diff << endl;
                    }
                    diff += 1;
                }
                count += 1;
            }
        }
    }

    if (valid && count == 8)
        cout << "valid" << endl;
    else
        cout << "invalid" << endl;

    return 0;
}
#include<bits/stdc++.h>

using namespace std;

/** @brief Almost Union Find
 * 
 * We need to add an operation "move" to traditional union find that moves 
 * a single element from one distinct set to another. With a traditional union
 * find data structure, this would be problematic if the moved element had 
 * "child" elements that were pointing to it since these children would also be
 * moved into the new distinct set.
 * 
 * To prevent this, we could naively keep track of all child nodes for any given
 * node and then move these children to a new parent when moving a target node, but 
 * this approach is costly O(n) since we need to elect a new parent and reset all
 * properties for each child
 * 
 * A better approach would be to first realize that running "move" on a leaf node
 * does not require any child manipulation since leaves don't have children. 
 * If we can guarantee that all elements remain leaves at all times, then move
 * will only cost O(1). To do this, we introduce dummy parent nodes that don't actually
 * correspond to set elements but simply group together elements in the disjoint sets.
*/

int parents[200005];
int ranks[200005];
int sizes[200005];
unsigned long sums[200005];

int find(int i) {
    if (parents[i] == i) return i;
    return parents[i] = find(parents[i]);
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);

    if (x != y) {
        if (ranks[x] < ranks[y]) {
            parents[x] = y;
            sizes[y] += sizes[x];
            sums[y] += sums[x];
        }
        else if (ranks[x] > ranks[y]) {
            parents[y] = x;
            sizes[x] += sizes[y];
            sums[x] += sums[y];
        }
        else {
            parents[y] = x;
            ranks[x] += 1;
            sizes[x] += sizes[y];
            sums[x] += sums[y];
        }
    }
}

void move(int x, int y) {
    // elements can only be leaves so we move freely
    int x_root = find(x);
    int y_root = find(y);

    if (x_root != y_root) {
        parents[x] = y_root;
        sizes[x_root]--;
        sizes[y_root]++;
        sums[x_root] -= x;
        sums[y_root] += x;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    int i, j;
    int cmd, p, q;
    
    while (cin >> n >> m) {

        memset(parents, 0, sizeof(parents));
        memset(ranks, 0, sizeof(ranks));
        memset(sizes, 0, sizeof(sizes));
        memset(sums, 0, sizeof(sums));

        /**
         * setup initial tree with rank 1 such that parents 
         * are dummy nodes and children are real DS elements
        */
        for (i=1, j=n+1; i<=n; i++, j++) {
            parents[i] = j;
            parents[j] = j;
            ranks[j] = 1;
            sizes[j] = 1;
            sums[j] = i;
        }

        for (int i=0; i<m; i++) {
            cin >> cmd;

            if (cmd == 1) {
                // union sets containing p and q
                cin >> p >> q;
                Union(p, q);
            } 
            else if (cmd == 2) {
                // move p to set of q
                cin >> p >> q;
                move(p, q);
            }
            else if (cmd == 3) {
                // print size and sum of p
                cin >> p;
                cout << sizes[find(p)] << ' ' << sums[find(p)] << '\n';
            }
        }

    }


    return 0;
}

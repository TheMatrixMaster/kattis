/** @brief fenwick tree
 * 
 * Fenwick tree is a binary indexed search tree that allows two special operations:
 * 
 * 1) Increment / Set an element in an array in O(log(n)) time
 * 2) Calculate the sum of the first n elements in an array in O(log(n)) time
 * 
 * Fenwick tree has recursive structure such that leaves correspond to 
 * individual items in the array and parent nodes carry the sum of its subtree.
 * Thus, the root node carries the sum of the entire array, so on and so forth.
 * This allows us to lose the right child of every inner node since the parent 
 * node value will cover all previous array elements + the value of the immediate
 * right child. The fenwick tree essentially blocks of the partial sums of the array
 * into multiples of 2 such that each time we traverse the tree to find the sum
 * of the first n integers, we only need to traverse O(log(n)) nodes with pre-computed
 * sums.
 * 
*/

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll fenwick_tree[5000005];

/** @brief Query operation on fenwick tree
 * 
 * To query the sum of the first n elements of the 
 * fenwick tree, we sum up the nth node and all its ancestors
 * 
 * @param index of last element to include in sum
 * @return sum of first index+1 elements in array
*/
ll query(int index)
{
    ll sum = 0;
    index = index + 1; // BIT is 1 indexed

    while (index > 0) {
        sum += fenwick_tree[index];

        /** @brief bit manipulation trick to go to parent
         * 
         * To go to parent of index i, we look at the binary form of i
         * bin(i) has bits set to 1 which represent the ancestor blocks that 
         * sum previous prefix sums at intervals of power of 2. Thus, we can
         * navigate to the parent node by flipping the last set bit from 1 to 0.
         * 
         * ex: parent[5] = 4 since 101 -> 100
         * ex: parent[10] = 8 since 1010 -> 1000
         * ex: parent[11] = 10 since 1011 -> 1010
         * 
         * Essentially, this operation brings us to the next smallest sum of powers of 2
         * which corresponds to the node that holds the prefix sum for that range.
         * 
         * index & (-index) gives us the least (rightmost) set bit because 
         * -index = (~index)+1
         * 
         * ex: let index = 101100, 
         * Then -index = 010011 + 1 = 010100
         * Thus, index & -index = 101100 & 010100 = 000100
        */
        index -= index & (-index);
    }
    return sum;
}

/** @brief Update operation on Fenwick Tree
 * 
 * When updating the value at array index i, we need to
 * update all nodes in the fenwick tree whose partial sum
 * includes index i. Since the right child of all inner nodes
 * are dropped, the tree only contains left child nodes. Thus,
 * if we are looking for the true ancestors of a node i such that
 * ancestor[i] has a partial sum that includes i, we need to look for 
 * ancestor nodes that have blocked off a larger power of 2 range (on the right)
 * 
 * To do this, we can use a bit manipulation trick where we add the least set bit 
 * to the current index's binary representation.
 * 
 * ex: ancestor[5] = 6 since 101 + 001 = 110
 * ex: ancestor[15] = 16 since 1111 + 0001 = 10000
 * ex: ancestor[6] = 8 since 1010 + 0010 = 1100
 * ex: ancestor[8] = 16 since 1000 + 1000 = 10000
 * 
 * Essentially, we are looking for the next largest sum of powers of 2
 * since that corresponding node would have a partial sum that immediately 
 * includes the value at node i
 * 
 * @param index of element to update
 * @param val for element at index to take
 * @param n size of the array
 * @return Void
*/
void update(int index, int val, int n)
{
    index = index + 1;

    while (index <= n) {
        fenwick_tree[index] += val;
        index += index & (-index);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    char cmd;
    int index, val;

    for (int i=0; i<q; i++) {
        cin >> cmd;
        if (cmd == '+') {
            cin >> index >> val;
            update(index, val, n);
        }
        else if (cmd == '?') {
            cin >> index;
            cout << query(index-1) << '\n';
        }
    }

    return 0;
}
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int n, m, h, tree_size;
int cmd, i, v, j;

// long long min(long long a, long long b) {
//     if (a > b)
//         return b;
//     else
//         return a;
// }

long long init(vector<long long> &tree, vector<long long> &arr, long long node,
               long long start, long long end) {
    if (start == end) {
        return tree[node] = arr[start];
    }
    long long mid = (start + end) / 2;
    return tree[node] = min(init(tree, arr, node * 2, start, mid),
                            init(tree, arr, node * 2 + 1, mid + 1, end));
}

long long query(vector<long long> &tree, long long node, long long start,
                long long end, long long left, long long right) {
    if (end < left || right < start) return 1e9 + 10;
    if (left <= start && end <= right) return tree[node];
    long long mid = (start + end) / 2;
    return min(query(tree, node * 2, start, mid, left, right),
               query(tree, node * 2 + 1, mid + 1, end, left, right));
}

long long update(vector<long long> &tree, long long node, long long start,
                 long long end, long long index, long long val) {
    if (index < start || end < index) return tree[node];
    if (start == end) return tree[node] = val;
    if (start != end) {
        long long mid = (start + end) / 2;
        return tree[node] =
                   min(update(tree, node * 2, start, mid, index, val),
                       update(tree, node * 2 + 1, mid + 1, end, index, val));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<long long> arr(n + 10);
    h = (int)ceil(log2(n));
    tree_size = (1 << (h + 1));
    vector<long long> tree(tree_size);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    init(tree, arr, 1, 1, n);
    cin >> m;
    for (int a = 0; a < m; a++) {
        cin >> cmd;
        if (cmd == 1) {  // update
            cin >> i >> v;
            arr[i] = v;
            update(tree, 1, 1, n, i, v);
        } else {  // query
            cin >> i >> j;
            cout << query(tree, 1, 1, n, i, j) << '\n';
        }
    }
}
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int n, m, h, tree_size;
int cmd, i, v, j;
long long init(vector<long long> &tree, vector<long long> &arr, long long node,
               long long start, long long end) {
    if (start == end) {
        return tree[node] = start;
    }
    long long mid = (start + end) / 2;
    long long idx1 = init(tree, arr, node * 2, start, mid);
    long long idx2 = init(tree, arr, node * 2 + 1, mid + 1, end);
    if (arr[idx1] <= arr[idx2]) {
        return tree[node] = idx1;
    } else
        return tree[node] = idx2;
}

long long update(vector<long long> &tree, vector<long long> &arr,
                 long long node, long long start, long long end,
                 long long index) {
    if (index < start || end < index) {
        return tree[node];
    }
    if (start == end) {
        return tree[node] = index;
    }

    if (start != end) {
        long long mid = (start + end) / 2;
        long long idx1 = update(tree, arr, node * 2, start, mid, index);
        long long idx2 = update(tree, arr, node * 2 + 1, mid + 1, end, index);
        // cout << idx1 << ' ' << idx2 << ' ' << arr[idx1] << ' ' << arr[idx2]
        //      << '\n';
        if (arr[idx1] <= arr[idx2]) {
            return tree[node] = idx1;
        }
        return tree[node] = idx2;
    }
}

long long query(vector<long long> &tree, vector<long long> &arr, long long node,
                long long start, long long end, long long left,
                long long right) {
    if (end < left || right < start) return -1;
    if (left <= start && end <= right) return tree[node];
    long long mid = (start + end) / 2;
    long long idx1 = query(tree, arr, node * 2, start, mid, left, right);
    long long idx2 = query(tree, arr, node * 2 + 1, mid + 1, end, left, right);
    if (idx1 == -1) {
        return idx2;
    } else if (idx2 == -1) {
        return idx1;
    }
    if (arr[idx1] <= arr[idx2]) {
        return idx1;
    } else
        return idx2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<long long> arr(n + 10);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    h = (int)ceil(log2(n));
    tree_size = 1 << (h + 1);
    vector<long long> tree(tree_size);
    init(tree, arr, 1, 1, n);
    cin >> m;
    for (int k = 1; k <= m; k++) {
        cin >> cmd;
        // cout << "k " << k << '\n';
        if (cmd == 1) {
            cin >> i >> v;
            arr[i] = v;
            // cout << "update" << '\n';
            update(tree, arr, 1, 1, n, i);
            // for (int i = 1; i <= 9; i++) {
            //     cout << tree[i] << ' ';
            // }
            // cout << '\n';
        } else {
            cin >> i >> j;
            // cout << "query" << '\n';
            cout << query(tree, arr, 1, 1, n, i, j) << '\n';
            // for (int i = 1; i <= 9; i++) {
            //     cout << tree[i] << ' ';
            // }
            // cout << '\n';
        }
    }
}
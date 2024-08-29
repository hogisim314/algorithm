#include <memory.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int tc;
int n, m;
int h, tree_size;
int pos[100100];  // 숫자가 현재 있는 인덱스
int q;
int insert_idx;

int init(vector<int> &tree, vector<int> &arr, int node, int start, int end) {
    if (start == end) {
        if (arr[start]) {
            return tree[node] = 1;
        } else
            return tree[node] = 0;
    }
    int mid = (start + end) / 2;
    return tree[node] = init(tree, arr, node * 2, start, mid) +
                        init(tree, arr, node * 2 + 1, mid + 1, end);
}

void update(vector<int> &tree, int node, int start, int end, int index,
            int diff) {
    if (index < start || end < index) return;
    tree[node] += diff;
    if (start != end) {
        int mid = (start + end) / 2;
        update(tree, node * 2, start, mid, index, diff);
        update(tree, node * 2 + 1, mid + 1, end, index, diff);
    }
}

int query(vector<int> &tree, int node, int start, int end, int left,
          int right) {
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return query(tree, node * 2, start, mid, left, right) +
           query(tree, node * 2 + 1, mid + 1, end, left, right);
}

void debug(vector<int> &tree, vector<int> &arr) {
    cout << '\n' << "debug" << '\n';
    for (int i = 1; i < tree_size; i++) {
        cout << tree[i] << ' ';
    }
    cout << '\n';
    for (int i = 1; i <= n + m; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        vector<int> arr(n + m + 10);
        h = (int)ceil(log2(n + m));
        tree_size = 1 << (h + 1);
        vector<int> tree(tree_size);
        for (int i = m + 1; i <= n + m; i++) {
            arr[i] = i - m;
            pos[i - m] = i;  // 즉 3은 현재 6에 있다.
        }
        insert_idx = m;
        init(tree, arr, 1, 1, n + m);
        // debug(tree, arr);
        for (int i = 1; i <= m; i++) {
            cin >> q;
            cout << query(tree, 1, 1, n + m, 1, pos[q] - 1) << ' ';
            update(tree, 1, 1, n + m, pos[q], -1);
            pos[q] = insert_idx;
            // debug(tree, arr);
            update(tree, 1, 1, n + m, insert_idx, 1);
            // debug(tree, arr);
            insert_idx--;
        }
        cout << '\n';
    }
}
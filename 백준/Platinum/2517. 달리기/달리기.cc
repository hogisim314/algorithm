#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
int n;
int fast;
int idx;
vector<pair<int, int>> order;
vector<int> result(500500);
int h, tree_size;

int sum(vector<int> &tree, int node, int start, int end, int left, int right) {
    if (right < start || end < left) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    return sum(tree, node * 2, start, mid, left, right) +
           sum(tree, node * 2 + 1, mid + 1, end, left, right);
}
void update(vector<int> &tree, int node, int start, int end, int index,
            int diff) {
    if (index < start || end < index) {
        return;
    }
    tree[node] += diff;
    if (start != end) {
        int mid = (start + end) / 2;
        update(tree, node * 2, start, mid, index, diff);
        update(tree, node * 2 + 1, mid + 1, end, index, diff);
    }
}

void debug(vector<int> &tree) {
    for (int i = 0; i <= tree_size; i++) {
        cout << tree[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    h = (int)ceil(log2(n));
    tree_size = 1 << (h + 1);
    vector<int> tree(tree_size);
    for (int i = 1; i <= n; i++) {
        cin >> fast;
        order.push_back(make_pair(fast, i));
    }
    sort(order.begin(), order.end(), greater<pair<int, int>>());
    // debug(tree);
    for (int i = 0; i < order.size(); i++) {
        fast = order[i].first;
        idx = order[i].second;
        update(tree, 1, 1, n, idx, 1);
        // debug(tree);
        result[idx] = sum(tree, 1, 1, n, 1, idx - 1) + 1;
        // cout << result[idx] << '\n';
    }

    for (int i = 1; i <= n; i++) {
        cout << result[i] << '\n';
    }
}
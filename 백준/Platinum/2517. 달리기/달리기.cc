#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int n, h, tree_size;

bool custom_comp(pair<int, int> a, pair<int, int> b) {
    if (a.second < b.second) {
        return true;
    } else
        return false;
}

void update(vector<int> &tree, int node, int start, int end, int index,
            int diff) {
    if (index < start || end < index) return;
    tree[node] += diff;
    if (start != end) {
        long long mid = (start + end) / 2;
        update(tree, node * 2, start, mid, index, diff);
        update(tree, node * 2 + 1, mid + 1, end, index, diff);
    }
}

int query(vector<int> &tree, int node, int start, int end, int left,
          int right) {
    if (end < left || right < start) return 0;
    if (left <= start && end <= right) return tree[node];

    long long mid = (start + end) / 2;
    return query(tree, node * 2, start, mid, left, right) +
           query(tree, node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<pair<int, int> > arr(n);
    for (int i = 0; i < n; i++) {
        arr[i].first = i;
        cin >> arr[i].second;
    }

    h = (int)ceil(log2(n));
    tree_size = 1 << (h + 1);
    vector<int> tree(tree_size);
    vector<pair<int, int> > result(n);
    sort(arr.begin(), arr.end(), custom_comp);

    for (int i = 0; i < n; i++) {
        arr[i].second = i;
    }

    for (int i = n - 1; i >= 0; i--) {
        result[i].first = arr[i].first;
        result[i].second = query(tree, 1, 0, n - 1, 0, arr[i].first - 1) + 1;
        update(tree, 1, 0, n - 1, arr[i].first, 1);
    }

    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) {
        cout << result[i].second << '\n';
    }
}
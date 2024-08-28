#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int n, h;
long long tree_size;
long long ans;
long long num;

void update(vector<long long> &tree, long long node, long long start,
            long long end, long long index, long long diff) {
    if (index < start || end < index) return;
    tree[node] += diff;
    if (start != end) {
        long long mid = (start + end) / 2;
        update(tree, node * 2, start, mid, index, diff);
        update(tree, node * 2 + 1, mid + 1, end, index, diff);
    }
}

int query(vector<long long> &tree, long long node, long long start,
          long long end, long long left, long long right) {
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
    vector<pair<int, int> > arr;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        arr.push_back(make_pair(num, i));
    }

    h = (int)ceil(log2(n));
    tree_size = 1 << (h + 1);
    vector<long long> tree(tree_size);
    vector<pair<long long, long long> > result(n);

    sort(arr.begin(), arr.end());
    // for (int i = 0; i < arr.size(); i++) {
    //     cout << arr[i].first << ' ' << arr[i].second << '\n';
    // }
    for (int i = 0; i < n; i++) {
        update(tree, 1, 1, n, arr[i].second, 1);
        if (arr[i].second == n) {
            result[i].first = 0;
            continue;
        }
        result[i].first = query(tree, 1, 1, n, arr[i].second + 1, n);
    }

    for (int i = 0; i < result.size(); i++) {
        ans += result[i].first;
    }

    cout << ans;
}
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int n;
int num;
int h, tree_size;
int arrB[500100];
vector<pair<int, int> > arrA;
vector<pair<int, int> > v;
vector<int> tree;
int idx;
long long ans;
int binary_search_index(int key) {
    int left = 0;
    int right = n;

    while (left + 1 < right) {
        int mid = (left + right) / 2;
        if (key < arrA[mid].first) {
            right = mid;
        } else if (arrA[mid].first <= key) {
            left = mid;
        }
    }
    return arrA[left].second;
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        arrA.push_back(make_pair(num, i));
    }
    sort(arrA.begin(), arrA.end());
    for (int i = 1; i <= n; i++) {
        cin >> arrB[i];
        idx = binary_search_index(arrB[i]);
        v.push_back(make_pair(idx, i));
    }
    h = (int)ceil(log2(n));
    tree_size = 1 << (h + 1);
    tree.resize(tree_size);
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        update(tree, 1, 1, n, v[i].second, 1);
        if (v[i].second == n) continue;
        ans += query(tree, 1, 1, n, v[i].second + 1, n);
    }
    cout << ans;
}
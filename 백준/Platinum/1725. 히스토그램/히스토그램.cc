#include <limits.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
long long n, m, k;
int tree_size, h;
long long ans = 0;
long long init(vector<long long> &arr, vector<long long> &tree, long long node,
               long long start, long long end) {
    if (start == end) {
        ans = max(ans, arr[start]);
        return tree[node] = start;
    }

    long long mid = (start + end) / 2;
    long long idx1 = init(arr, tree, node * 2, start, mid);
    long long idx2 = init(arr, tree, node * 2 + 1, mid + 1, end);
    if (arr[idx1] <= arr[idx2]) {
        ans = max(ans, (mid - start + 1) * arr[idx1]);
        return tree[node] = idx1;
    } else {
        ans = max(ans, (end - mid) * arr[idx2]);
        return tree[node] = idx2;
    }
}

long long get_min(vector<long long> &tree, vector<long long> &arr,
                  long long node, long long start, long long end,
                  long long left, long long right) {
    if (left > end || right < start)
        return 1e9;  // min 리턴할때는 이거 바꿔줘야함****

    if (left <= start && end <= right) {
        return tree[node];
    }

    long long mid = (start + end) / 2;
    long long idx1 = get_min(tree, arr, node * 2, start, mid, left, right);
    long long idx2 =
        get_min(tree, arr, node * 2 + 1, mid + 1, end, left, right);
    if (idx1 == 1e9) {
        return idx2;
    } else if (idx2 == 1e9) {
        return idx1;
    } else {
        if (arr[idx1] <= arr[idx2]) {
            return idx1;
        }
        return idx2;
    }
    // return min(get_min(tree, arr, node * 2, start, mid, left, right),
    //            get_min(tree, arr, node * 2 + 1, mid + 1, end, left, right));
}

void divideAndConquer(vector<long long> &tree, vector<long long> &arr,
                      long long left, long long right) {
    if (left > right) return;
    long long treeIdx = get_min(tree, arr, 1, 0, n - 1, left, right);
    ans = max(ans, (long long)arr[treeIdx] * (right - left + 1));
    divideAndConquer(tree, arr, left, treeIdx - 1);
    divideAndConquer(tree, arr, treeIdx + 1, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    h = (int)ceil(log2(n));
    vector<long long> arr(n);
    tree_size = (1 << (h + 1));  // 등비수열 합 공식이용
    vector<long long> tree(tree_size);
    for (int i = 0; i <= n - 1; i++) {
        long long num;
        cin >> num;
        arr[i] = num;
    }

    init(arr, tree, 1, 0, n - 1);

    divideAndConquer(tree, arr, 0, n - 1);
    cout << ans;
}
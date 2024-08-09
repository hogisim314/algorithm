#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
#define MAX 1000000
int n;
int h;
long long tree_size;
int A, B, C;
long long init(vector<long long>& tree, vector<long long>& arr, long long node,
               long long start, long long end) {
    if (start == end) {
        tree[node] = arr[start];
    }
    long long mid = (start + end) / 2;
    return init(tree, arr, node * 2, start, mid) +
           init(tree, arr, node * 2 + 1, mid + 1, end);
}

long long query(vector<long long>& tree, long long node, long long start,
                long long end, long long cnt) {
    // if (end < left || right < start) return 0;  // 등호 떼버리기
    // if (left <= start && end <= right) return tree[node];
    if (start == end) {
        return start;
    }
    long long mid = (start + end) / 2;
    if (cnt <= tree[node * 2]) {
        return query(tree, node * 2, start, mid, cnt);
    } else
        return query(tree, node * 2 + 1, mid + 1, end, cnt - tree[node * 2]);
}

void update(vector<long long>& tree, long long node, long long start,
            long long end, long long index, long long diff) {
    if (index < start || end < index) return;
    tree[node] += diff;
    if (start != end) {
        long long mid = (start + end) / 2;
        update(tree, node * 2, start, mid, index, diff);
        update(tree, node * 2 + 1, mid + 1, end, index, diff);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<long long> arr(MAX + 10);
    h = (int)ceil(log2(MAX));
    tree_size = (1 << (h + 1));
    vector<long long> tree(tree_size);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A;
        if (A == 1) {  // 사탕을 꺼내는 경우
            cin >> B;  // 사탕의 순위 B
            long long res = query(tree, 1, 1, MAX, B);
            arr[res]--;
            update(tree, 1, 1, MAX, res, -1);
            cout << res << '\n';
        } else if (A == 2) {  // 사탕을 넣거나 빼는 경우
            cin >> B >> C;
            arr[B] += C;
            update(tree, 1, 1, MAX, B, C);
            // cout << "root" << ' ' << tree[1] << '\n';
        }
    }
}
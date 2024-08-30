#include <algorithm>
#include <iostream>
using namespace std;
int n, m;
int treeHeight[1000100];
int MAX;
int MIN = 1e9 + 10;

long long check(int cut) {
    long long take = 0;
    for (int i = 1; i <= n; i++) {
        if (treeHeight[i] <= cut) {
            continue;
        }
        take += treeHeight[i] - cut;
    }
    return take;
}

int parametric_search() {
    int lo = 0;
    int hi = MAX + 1;

    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid) < (long long)m) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return lo;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> treeHeight[i];
        MAX = max(MAX, treeHeight[i]);
        MIN = min(MIN, treeHeight[i]);
    }
    cout << parametric_search();
}
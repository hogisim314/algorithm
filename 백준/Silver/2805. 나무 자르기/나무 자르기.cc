#include <algorithm>
#include <iostream>
using namespace std;
int N, M;
int arr[1111111];
int lo, hi, mid, ans;

bool check(int h) {
    long long sum = 0;
    for (int i = 1; i <= N; i++) {
        if (arr[i] < h) continue;
        sum += (arr[i] - h);
    }
    if (sum >= M) {
        ans = max(ans, h);
        return true;
    }
    return false;
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        hi = max(hi, arr[i]);
    }
    while (lo + 1 < hi) {
        mid = lo + ((hi - lo) / 2);
        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << ans;
}
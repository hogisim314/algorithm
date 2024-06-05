#include <algorithm>
#include <iostream>
using namespace std;
int n, m, l;
int arr[55];
int maxx;
int ans = 1000000000;
bool check(int mid) {
    int cnt = 0;
    for (int i = 1; i <= n + 1; i++) {
        int left = arr[i - 1];
        int right = arr[i];
        if (right - left < mid) continue;
        if ((right - left) % mid == 0) {
            cnt += (right - left) / mid - 1;
        } else {
            cnt += (right - left) / mid;
        }
    }
    // cout << cnt << ' ';
    if (cnt <= m) {
        ans = mid;
        return true;
    }
    return false;
}

int main() {
    cin >> n >> m >> l;
    arr[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        maxx = max(maxx, arr[i] - arr[i - 1]);
    }
    arr[n + 1] = l;
    if (maxx == 0) {
        maxx = l;
    }
    // cout << maxx << '\n';
    sort(arr + 1, arr + n + 2);
    if (m == 0) {
        cout << maxx;
        return 0;
    }
    int lo = 1;
    int hi = l;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        // cout << lo << ' ' << hi << ' ' << mid << ' ';
        bool res = check(mid);
        // cout << res <<'\n';
        if (res) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans;
}
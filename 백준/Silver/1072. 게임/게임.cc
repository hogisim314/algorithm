#include <limits.h>

#include <algorithm>
#include <iostream>
using namespace std;
long long x, y, z;
long long ans = INT_MAX;
int main() {
    cin >> x >> y;
    z = y * 100 / x;

    long long lo = 0, hi = 1'000'000'500;
    while (lo + 1 < hi) {
        long long mid = lo + (hi - lo) / 2;
        if ((y + mid) * 100 / (x + mid) >= z + 1) {
            hi = mid;
            ans = min(ans, mid);
        } else {
            lo = mid;
        }
    }
    if (ans == INT_MAX) {
        cout << -1;
        return 0;
    }
    cout << ans;
}
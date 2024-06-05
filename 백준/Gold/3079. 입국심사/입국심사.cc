#include <algorithm>
#include <iostream>
using namespace std;

long long n, m, t[100004];
long long low, high, mid;
long long minn = 1000000001;
long long ans;

bool check(long long mid) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (mid / t[i]);
    }
    if (sum >= m) {
        ans = mid;
        return true;
    } else
        return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        minn = min(minn, t[i]);
    }

    low = 0;
    high = minn * m + 1;
    while (low + 1 < high) {
        mid = (low + high) / 2;
        bool res = check(mid);
        if (res) {
            high = mid;
        } else
            low = mid;
    }
    cout << ans;
}
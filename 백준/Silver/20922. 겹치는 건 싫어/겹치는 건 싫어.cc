#include <memory.h>

#include <algorithm>
#include <iostream>
using namespace std;
int n, k;
int cnt[100100];
int arr[200100];
int l = 1, r = 0;
int ans = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    while (r <= n) {
        if (cnt[arr[r]] < k) {
            cnt[arr[r]]++;
            r++;
            ans = max(ans, r - l);
        } else {
            cnt[arr[l]]--;
            l++;
        }
    }
    cout << ans;
}
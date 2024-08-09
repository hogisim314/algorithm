#include <algorithm>
#include <iostream>
#include <memory.h>
using namespace std;
int tc;
int n;
int arr[1111];
int dp[1111][1111];
int solve(int turn, int left, int right) {
    if (left > right) return 0;
    if (dp[left][right]) {
        return dp[left][right];
    }
    if (turn % 2 == 1) {
        return dp[left][right] = min(solve(turn + 1, left + 1, right),
                                     solve(turn + 1, left, right - 1));
    } else {
        return dp[left][right] =
                   max(solve(turn + 1, left + 1, right) + arr[left],
                       solve(turn + 1, left, right - 1) + arr[right]);
    }
}

int main() {
    cin >> tc;
    while (tc--) {
        memset(arr, 0, sizeof(arr));
        memset(dp, 0, sizeof(dp));
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        solve(0, 1, n);
        cout << dp[1][n] << '\n';
    }
}
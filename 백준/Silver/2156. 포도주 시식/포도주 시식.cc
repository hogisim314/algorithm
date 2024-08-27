#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int n;
int drink[11111];
int dp[11111][3];  // i번째를 연속으로 먹었다고 했을 때 j번 먹은 것
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> drink[i];
    }
    dp[1][1] = drink[1];
    for (int i = 2; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
        dp[i][1] =
            max(dp[i - 1][0], max(dp[i - 2][1], dp[i - 2][2])) + drink[i];
        dp[i][2] = dp[i - 1][1] + drink[i];
    }

    cout << max(dp[n][1], max(dp[n][2], max(dp[n - 1][1], dp[n - 1][2])));
}
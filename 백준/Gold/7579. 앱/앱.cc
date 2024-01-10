#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, m;
int mem[111];
int cost[111];
int dp[111][11111];  // i번째 앱까지 확인했을 때 j의 비용으로 얻을 수 있는
int sum;
// 최대의 메모리.
int ans = 11111;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> mem[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
        sum += cost[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j >= cost[i]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + mem[i]);
                if (dp[i][j] >= m) {
                    ans = min(ans, j);
                }
            } else {
                dp[i][j] = dp[i - 1][j];
                if (dp[i][j] >= m) {
                    ans = min(ans, j);
                }
            }
        }
    }
    cout << ans;
}
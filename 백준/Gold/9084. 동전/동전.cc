#include <memory.h>

#include <algorithm>
#include <iostream>
using namespace std;
int tc, n, m;
int w[22];
int dp[22][10005];
int main() {
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        memset(dp, 0, sizeof(dp));
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> w[i];
        }
        cin >> m;
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = 1;  // 안내는 경우
            for (int j = 1; j <= m; j++) {
                for (int k = 0; k <= j / w[i]; k++) {
                    dp[i][j] += dp[i - 1][j - (w[i] * k)];
                }
            }
        }
        cout << dp[n][m] << '\n';
        ;
    }
}
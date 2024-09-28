#include <algorithm>
#include <iostream>
using namespace std;
int tc;
long long dp[11111][4];
int n;
int main() {
    cin >> tc;
    dp[0][0] = 1;
    for (int t = 1; t <= tc; ++t) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= 3; ++j) {
                if (i - j < 0) continue;
                if (dp[i][j] > 0) continue;
                for (int k = 0; k <= j; ++k) {
                    dp[i][j] += dp[i - j][k];
                }
            }
        }
        cout << dp[n][1] + dp[n][2] + dp[n][3] << '\n';
    }
}
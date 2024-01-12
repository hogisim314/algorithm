#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;
int house[17][17];
int dp[17][17][3];
int ans;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> house[i][j];
        }
    }

    dp[1][1][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (house[i][j] == 1) continue;
            if (j + 2 <= n && house[i][j + 2] != 1) {
                dp[i][j + 1][0] += dp[i][j][0];
            }
            if (j + 2 <= n && i + 1 <= n && house[i][j + 2] != 1 &&
                house[i + 1][j + 1] != 1 && house[i + 1][j + 2] != 1) {
                dp[i][j + 1][2] += dp[i][j][0];
            }
            if (i + 2 <= n && house[i + 2][j] != 1) {
                dp[i + 1][j][1] += dp[i][j][1];
            }
            if (i + 2 <= n && j + 1 <= n && house[i + 2][j] != 1 &&
                house[i + 2][j + 1] != 1 && house[i + 1][j + 1] != 1) {
                dp[i + 1][j][2] += dp[i][j][1];
            }
            if (j + 2 <= n && i + 1 <= n && house[i + 1][j + 2] != 1) {
                dp[i + 1][j + 1][0] += dp[i][j][2];
            }
            if (i + 2 <= n && j + 1 <= n && house[i + 2][j + 1] != 1) {
                dp[i + 1][j + 1][1] += dp[i][j][2];
            }
            if (i + 2 <= n && j + 2 <= n && house[i + 1][j + 2] != 1 &&
                house[i + 2][j + 1] != 1 && house[i + 2][j + 2] != 1) {
                dp[i + 1][j + 1][2] += dp[i][j][2];
            }
        }
    }

    ans = dp[n][n - 1][0] + dp[n - 1][n][1] + dp[n - 1][n - 1][2];
    cout << ans;
}

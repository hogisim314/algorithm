#include <algorithm>
#include <iostream>
using namespace std;
#define mod 100000
int w, h;
int dp[111][111][2][2];
//
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> w >> h;

    for (int i = 1; i <= w; i++) {
        dp[i][1][0][0] = 1;
    }

    for (int j = 1; j <= h; j++) {
        dp[1][j][1][0] = 1;
    }

    for (int i = 2; i <= w; i++) {
        for (int j = 2; j <= h; j++) {
            dp[i][j][1][1] = dp[i][j - 1][0][0] % mod;
            dp[i][j][1][0] = (dp[i][j - 1][1][1] + dp[i][j - 1][1][0]) % mod;
            dp[i][j][0][1] = dp[i - 1][j][1][0] % mod;
            dp[i][j][0][0] = (dp[i - 1][j][0][1] + dp[i - 1][j][0][0]) % mod;
        }
    }
    int ans = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ans += dp[w][h][i][j];
            ans %= 100000;
        }
    }
    cout << ans;
}
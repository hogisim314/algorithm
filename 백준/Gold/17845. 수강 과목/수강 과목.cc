#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, k;
int w[1111];
int v[1111];
int dp[1111][11111];
int i, t;
int main() {
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> v[i] >> w[i];
    }

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            if (j >= w[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[k][n];
}
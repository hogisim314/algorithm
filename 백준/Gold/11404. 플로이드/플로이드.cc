#include <limits.h>
#include <math.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, m;
int a, b, c;
vector<pair<int, int> > Edges[111];
long long dp[111][111];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = INT_MAX;
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        if (dp[a][b] > c) {
            dp[a][b] = c;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i][j] == INT_MAX) {
                cout << 0 << ' ';
                continue;
            }
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
}
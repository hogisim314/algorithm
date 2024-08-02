#include <algorithm>
#include <iostream>
using namespace std;
#define MAX 1'000'000'000
int n, m, k;
long long dp[111][111];  // dp[i][j]는 a i개, z j개 만드는 방법의 수
string ans;
long long recursion(int i, int j) {
    if (i == 0 || j == 0) return dp[i][j] = 1;
    if (dp[i][j] != 0) return dp[i][j];
    dp[i][j] = recursion(i - 1, j) + recursion(i, j - 1);
    if (dp[i][j] >= MAX) {
        return dp[i][j] = MAX;
    }
    return dp[i][j];
}

void build_string(int i, int j, int k) {
    if (i == 0) {
        for (int idx = 0; idx < j; idx++) {
            ans += 'z';
        }
        return;
    }
    if (j == 0) {
        for (int idx = 0; idx < i; idx++) {
            ans += 'a';
        }
        return;
    }
    if (dp[i - 1][j] >= k) {
        ans += 'a';
        build_string(i - 1, j, k);
    } else if (dp[i - 1][j] < k) {
        ans += 'z';
        build_string(i, j - 1, k - dp[i - 1][j]);
    }
}

int main() {
    cin >> n >> m >> k;
    recursion(n, m);
    if (dp[n][m] < k) {
        cout << -1;
        return 0;
    }
    build_string(n, m, k);
    cout << ans;
}
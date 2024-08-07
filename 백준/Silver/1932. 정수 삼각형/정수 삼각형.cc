#include <algorithm>
#include <iostream>
using namespace std;
int n;
int arr[555][555];
int dp[555][555];
int ans;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> arr[i][j];
        }
    }
    dp[1][1] = arr[1][1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans;
}
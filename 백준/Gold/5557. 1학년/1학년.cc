#include <algorithm>
#include <iostream>
using namespace std;
int n;
int arr[111];
long long dp[111][25];  // dp[i][j] = k i번째까지 수를 활용해서 합 J를 만드는
                        // 경우의 수 k
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    dp[1][arr[1]] = 1;
    for (int i = 2; i <= n - 1; i++) {
        for (int j = 0; j <= 20; j++) {
            if (j - arr[i] >= 0) {
                dp[i][j] += dp[i - 1][j - arr[i]];
            }
            if (j + arr[i] <= 20) {
                dp[i][j] += dp[i - 1][j + arr[i]];
            }
        }
    }
    cout << dp[n - 1][arr[n]];
}
#include <algorithm>
#include <iostream>
using namespace std;
int n;
int dp[62505];
int tmp;
int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    cout << dp[n];
}
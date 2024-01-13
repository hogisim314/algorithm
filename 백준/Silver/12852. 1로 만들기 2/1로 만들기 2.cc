#include <algorithm>
#include <iostream>
using namespace std;
int n;
int dp[1000005];
int previous[1000005];
int idx;
int main() {
    cin >> n;
    for (int i = 2; i <= 1000000; i++) {
        dp[i] = dp[i - 1] + 1;
        previous[i] = i - 1;
        if (i % 2 == 0 && dp[i / 2] + 1 < dp[i]) {
            dp[i] = dp[i / 2] + 1;
            previous[i] = i / 2;
        }
        if (i % 3 == 0 && dp[i / 3] + 1 < dp[i]) {
            dp[i] = dp[i / 3] + 1;
            previous[i] = i / 3;
        }
    }
    cout << dp[n] << '\n';
    idx = n;
    cout << idx << ' ';
    while (idx != 1) {
        cout << previous[idx] << ' ';
        idx = previous[idx];
    }
}
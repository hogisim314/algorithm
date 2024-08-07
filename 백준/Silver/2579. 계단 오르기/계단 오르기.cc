#include <algorithm>
#include <iostream>
using namespace std;

int n;
int arr[333];
int dp[333][3];  // 연속해서 온 계단의 갯수
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    dp[1][0] = arr[1];
    dp[2][0] = arr[2];
    dp[2][1] = arr[1] + arr[2];
    for (int i = 3; i <= n; i++) {
        dp[i][0] = max(dp[i - 2][1], dp[i - 2][0]) + arr[i];
        dp[i][1] = dp[i - 1][0] + arr[i];
    }
    cout << max(dp[n][0], max(dp[n][1], dp[n][2]));
}
#include <algorithm>
#include <iostream>
using namespace std;
int n;
int arr[111111][4];
int max_dp[3][4];
int min_dp[3][4];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i][1] >> arr[i][2] >> arr[i][3];
    }
    max_dp[1][1] = arr[1][1];
    max_dp[1][2] = arr[1][2];
    max_dp[1][3] = arr[1][3];
    min_dp[1][1] = arr[1][1];
    min_dp[1][2] = arr[1][2];
    min_dp[1][3] = arr[1][3];
    for (int i = 2; i <= n; i++) {
        max_dp[2][1] = max(max_dp[1][1], max_dp[1][2]) + arr[i][1];
        max_dp[2][2] =
            max(max_dp[1][1], max(max_dp[1][2], max_dp[1][3])) + arr[i][2];
        max_dp[2][3] = max(max_dp[1][2], max_dp[1][3]) + arr[i][3];

        max_dp[1][1] = max_dp[2][1];
        max_dp[1][2] = max_dp[2][2];
        max_dp[1][3] = max_dp[2][3];

        min_dp[2][1] = min(min_dp[1][1], min_dp[1][2]) + arr[i][1];
        min_dp[2][2] =
            min(min_dp[1][1], min(min_dp[1][2], min_dp[1][3])) + arr[i][2];
        min_dp[2][3] = min(min_dp[1][2], min_dp[1][3]) + arr[i][3];

        min_dp[1][1] = min_dp[2][1];
        min_dp[1][2] = min_dp[2][2];
        min_dp[1][3] = min_dp[2][3];
    }
    cout << max(max_dp[1][1], max(max_dp[1][2], max_dp[1][3])) << ' '
         << min(min_dp[1][1], min(min_dp[1][2], min_dp[1][3]));
}
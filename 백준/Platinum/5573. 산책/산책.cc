#include <algorithm>
#include <iostream>
using namespace std;
int n, h, w;
int arr[1111][1111];
int dp[1111][1111];
int main() {
    cin >> h >> w >> n;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> arr[i][j];
        }
    }
    dp[1][1] = n - 1;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (i - 1 >= 1) {
                if (dp[i - 1][j] % 2 == 0) {
                    dp[i][j] += dp[i - 1][j] / 2;
                } else {
                    if (arr[i - 1][j] == 1) {
                        dp[i][j] += (dp[i - 1][j] / 2);
                    } else if (arr[i - 1][j] == 0) {
                        dp[i][j] += 1 + (dp[i - 1][j] / 2);
                    }
                }
            }
            if (j - 1 >= 1) {
                if (dp[i][j - 1] % 2 == 0) {
                    dp[i][j] += dp[i][j - 1] / 2;
                } else {
                    if (arr[i][j - 1] == 1) {
                        dp[i][j] += 1 + (dp[i][j - 1] / 2);
                    } else if (arr[i][j - 1] == 0) {
                        dp[i][j] += (dp[i][j - 1] / 2);
                    }
                }
            }
        }
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (dp[i][j] % 2 == 1) {
                if (arr[i][j] == 0) {
                    arr[i][j] = 1;
                } else if (arr[i][j] == 1) {
                    arr[i][j] = 0;
                }
            }
            // cout << arr[i][j] << ' ';
        }
        // cout << '\n';
    }

    // for (int i = 1; i <= h; i++) {
    //     for (int j = 1; j <= w; j++) {
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    int curi = 1;
    int curj = 1;
    while (curi != h + 1 && curj != w + 1) {
        if (arr[curi][curj] == 1) {  // 오른쪽
            curj++;
        } else {  // 아래쪽
            curi++;
        }
        // cout << curi << ' ' << curj << '\n';
    }
    cout << curi << ' ' << curj << '\n';
}
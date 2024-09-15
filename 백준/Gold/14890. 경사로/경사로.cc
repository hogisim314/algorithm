#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int n, l;
int arr[111][111];
bool slideRow[111][111];
bool slideCol[111][111];
int ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> l;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> arr[i][j];
        }
    }
    // 행 보기
    for (int i = 1; i <= n; ++i) {
        bool flag = true;
        for (int j = 1; j <= n - 1; ++j) {
            int diff = abs(arr[i][j] - arr[i][j + 1]);
            if (diff >= 2) {
                flag = false;
                break;
            }
            if (diff == 0)
                continue;
            else if (diff == 1) {
                if (arr[i][j] == arr[i][j + 1] + 1) {
                    for (int k = j + 1; k < j + 1 + l; ++k) {
                        if (k > n || arr[i][k] != arr[i][j + 1] ||
                            slideRow[i][k]) {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) {
                        break;
                    } else {
                        for (int k = j + 1; k < j + 1 + l; ++k) {
                            slideRow[i][k] = 1;
                        }
                    }
                } else if (arr[i][j] + 1 == arr[i][j + 1]) {
                    for (int k = j; k > j - l; --k) {
                        if (k < 1 || arr[i][k] != arr[i][j] || slideRow[i][k]) {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) {
                        break;
                    } else {
                        for (int k = j; k > j - l; --k) {
                            slideRow[i][k] = 1;
                        }
                    }
                }
            }
        }
        if (flag) {
            ans++;
        }
    }

    // 열 보기
    for (int j = 1; j <= n; ++j) {
        bool flag = true;
        for (int i = 1; i <= n - 1; ++i) {
            int diff = abs(arr[i][j] - arr[i + 1][j]);
            if (diff >= 2) {
                flag = false;
                break;
            }
            if (diff == 0)
                continue;
            else if (diff == 1) {
                if (arr[i][j] == arr[i + 1][j] + 1) {
                    for (int k = i + 1; k < i + 1 + l; ++k) {
                        if (k > n || arr[k][j] != arr[i + 1][j] ||
                            slideCol[k][j]) {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) {
                        break;
                    } else {
                        for (int k = i + 1; k < i + 1 + l; ++k) {
                            slideCol[k][j] = 1;
                        }
                    }
                } else if (arr[i][j] + 1 == arr[i + 1][j]) {
                    for (int k = i; k > i - l; --k) {
                        if (k < 1 || arr[k][j] != arr[i][j] || slideCol[k][j]) {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) {
                        break;
                    } else {
                        for (int k = i; k > i - l; --k) {
                            slideCol[k][j] = 1;
                        }
                    }
                }
            }
        }
        if (flag) {
            ans++;
        }
    }
    cout << ans;
}
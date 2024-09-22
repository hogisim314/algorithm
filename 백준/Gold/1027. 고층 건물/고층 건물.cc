#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int n;
int h[55];
bool canSee[55][55];
int cnt[55];
int ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            // i랑 j의 기울기 식 구해놓고
            double slope = (double)(h[j] - h[i]) / (j - i);
            double yintercept = h[i] - (slope * i);
            bool flag = true;
            for (int k = i + 1; k <= j - 1; ++k) {
                if (h[k] < slope * k + yintercept)
                    continue;
                else {
                    flag = false;
                    break;
                }
            }
            canSee[i][j] = flag;
            canSee[j][i] = flag;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            if (canSee[i][j]) {
                cnt[i]++;
            }
        }
        ans = max(ans, cnt[i]);
    }
    cout << ans;
}
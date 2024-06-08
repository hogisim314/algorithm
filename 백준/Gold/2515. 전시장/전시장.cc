#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, s, h, c;
vector<pair<int, int>> v;
vector<int> height;
long long dp[300300][2];
// dp[i][0] : i번쨰를 고르지 않았을 떄의 얻을 수 있는 최대가격
// dp[i][1] : i번쨰를 골랐을 떄의 얻을 수 있는 최대가격

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> h >> c;
        height.push_back(h);
        v.push_back({h, c});
    }

    sort(v.begin(), v.end());
    sort(height.begin(), height.end());
    dp[0][0] = 0;
    dp[0][1] = v[0].second;
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        int idx = upper_bound(height.begin(), height.end(), v[i].first - s) -
                  height.begin();
        // cout << i << ' ' << idx << '\n';
        if (idx == 0) {
            dp[i][1] = v[i].second;
            continue;
        }
        dp[i][1] = max(dp[idx - 1][0], dp[idx - 1][1]) + v[i].second;
    }

    // for (int i = 0; i < n; i++) {
    //     cout << dp[i][0] << ' ' << dp[i][1] << '\n';
    // }

    cout << max(dp[n - 1][0], dp[n - 1][1]);
}
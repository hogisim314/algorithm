#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, k, a;
int dp[10100];  // dp[i]에서 i원을 만들 때 쓰는 가짓수.
vector<int> num;
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a;
        num.push_back(a);
    }
    dp[0] = 1;
    sort(num.begin(), num.end());

    for (int j = 0; j < n; j++) {
        for (int i = 1; i <= k; i++) {
            if (i < num[j]) continue;

            dp[i] += dp[i - num[j]];
        }
    }

    cout << dp[k];
}
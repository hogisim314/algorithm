#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int INF = 1e4 + 5;
const int K = 1e4 + 5;
int coins[N];
int dp[K];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i != n; i++) {
		cin >> coins[i];
	}
	dp[0] = 1;
	for (int j = 0; j != n; j++) {
		int coin = coins[j];
		for (int i = 1; i <= k; i++) {
			if (i - coin < 0) continue;
			dp[i] += dp[i - coin];
		}
	}
	cout << dp[k];
}
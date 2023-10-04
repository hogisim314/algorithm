#include <bits/stdc++.h>
using namespace std;
int hp[30];
int joy[30];
int dp[30][130];
int main() {
	int n;
	cin >> n;
	int max_hp = 100;
	for (int i = 1; i <= n; i++) {
		cin >> hp[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> joy[i];
	}
	int maxx = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < 100; j++) {
			if (j - hp[i] < 0) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - hp[i]] + joy[i]);
			}
			maxx = max(maxx, dp[i][j]);
		}
	}
	cout << maxx;
}
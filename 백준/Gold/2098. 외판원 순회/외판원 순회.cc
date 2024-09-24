#include <iostream>
#include <algorithm>
using namespace std;
int n;
int cost[17][17];
int dp[1 << 16][17];

/*int dfs(int state, int cur) {
	if (dp[state][cur] != 1e9) {
		return dp[state][cur];
	}

	if (state == (1 << n) - 1) { // 다 순회했다는거
		return
	}
	for (int i = 0; i < n; i++) {
		if (state & (1 << i)==0) {
			dp[state][cur] = min(dp[state][cur], dfs(state + (1 << i), i)+cost[cur][i]);
		}
	}
	return dp[state][cur];
}*/

int main() {
	cin >> n;

	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = 1e9;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cost[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		if (cost[0][i]) dp[(1 << i)][i] = cost[0][i];
	}

	for (int state = 1; state < (1 << n); state++) {
		for (int i = 0; i < n; i++) {
			if (!(state & (1 << i))) continue; //state에 i도시를 안지났었으면 패스
			for (int j = 0; j < n; j++) {
				if ((state & (1 << j)) >0 && cost[i][j] != 0) {
					dp[state][j] = min(dp[state][j], dp[state - (1 << j)][i] + cost[i][j]);
				}
			}
		}
	}

	cout << dp[(1 << n) - 1][0];
}
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int weight[111];
int value[111];
int dp[111][111111];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> weight[i];
		cin >> value[i];
	}
	for (int i = 1; i <= n; i++) {//i몇번째 물건
		for (int j = 1; j <= k; j++) {//j가 무게
			if (j < weight[i]) {
				dp[i][j] = dp[i - 1][j];//i번째 무게를 빼고 생각할 때 즉, 전무게까지의 최대 가치
			}
			else {//j>weight[i]-> i번째 담을수도 있음
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);//weight[i]빼고의 최대가치에 value[i]를 생각
			}
		}
	}
	cout << dp[n][k];
}
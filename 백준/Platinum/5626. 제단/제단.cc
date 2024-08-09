#include<iostream>
#include<stdio.h>
using namespace std;

int n;
int knowledge[10001];
int dp[10001][5002];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> knowledge[i];
	}

	if (knowledge[1] == 1 || knowledge[n] == 1)
	{
		cout << "0" << endl;
		return 0;
	}


	knowledge[1] = 0;
	dp[1][0] = 1;
	knowledge[n] = 0;

	for (int i = 2; i <= n; i++) {
		if (knowledge[i] != -1) {
			dp[i][knowledge[i]] = ((long long)dp[i-1][knowledge[i]] + (long long)dp[i-1][knowledge[i]+1] + (long long)dp[i-1][knowledge[i]-1]) % 1000000007;
			continue;
		}
		for (int j = 0; j <= i; j++) {
			if (j > 5000) break;
			dp[i][j] = ((long long)dp[i - 1][j] + (long long)dp[i - 1][j - 1] + (long long)dp[i - 1][j + 1]) % 1000000007;
		}
	}

	cout << dp[n][0] << endl;
}